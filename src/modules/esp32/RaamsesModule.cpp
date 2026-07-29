#include "configuration.h"

#if defined(ARCH_ESP32) && defined(HAS_RAAMSES)

#include "RaamsesModule.h"
#include "MeshService.h"
#include "Router.h"
#include "NodeDB.h"
#include "graphics/Screen.h"
#include "graphics/ScreenFonts.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <esp_wifi.h>

RaamsesModule *raamsesModule = nullptr;

// ─── screen drawing helpers ───────────────────────────────────

#if HAS_SCREEN
void RaamsesModule::drawSplashOnScreen()
{
    if (!screen) return;

    auto splashFrame = [](OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) {
        display->setFont(FONT_LARGE);
        display->setTextAlignment(TEXT_ALIGN_CENTER);
        display->drawString(display->getWidth() / 2 + x, 10 + y, "RAAMSES");
        display->setFont(FONT_SMALL);
        display->drawString(display->getWidth() / 2 + x, 40 + y, "agent alert console");
    };
    screen->startAlert(splashFrame);
}

void RaamsesModule::drawAlertOnScreen(const char *msg)
{
    if (!screen) return;

    std::string source(msg ? msg : "");
    auto alertFrame = [source](OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) {
        display->setFont(FONT_MEDIUM);
        display->setTextAlignment(TEXT_ALIGN_CENTER);
        display->drawString(display->getWidth() / 2 + x, 10 + y, "AGENT NEEDS");
        display->setFont(FONT_LARGE);
        display->drawString(display->getWidth() / 2 + x, 30 + y, "HELP!");
        if (!source.empty()) {
            display->setFont(FONT_SMALL);
            display->drawString(display->getWidth() / 2 + x, 50 + y, source.c_str());
        }
    };
    screen->startAlert(alertFrame);
}

void RaamsesModule::showStatusScreen()
{
    if (!screen) return;

    std::string msg = statusMessage;
    bool connected = wifiConnected;

    auto statusFrame = [msg, connected](OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) {
        int w = display->getWidth();
        int h = display->getHeight();

        // ── Main content area ──────────────────────────────
        display->setColor(WHITE);
        display->setFont(FONT_LARGE);
        display->setTextAlignment(TEXT_ALIGN_CENTER);
        display->drawString(w / 2 + x, 8 + y, "RAAMSES");

        display->setFont(FONT_SMALL);
        if (connected) {
            display->drawString(w / 2 + x, 30 + y, "Gateway connected");
        } else {
            display->drawString(w / 2 + x, 30 + y, "LoRa mesh mode");
        }

        // ── Bottom status bar (inverted: black bg, white text) ──
        const int barH = 16;
        int barY = h - barH;
        display->setColor(BLACK);
        display->fillRect(0 + x, barY + y, w, barH);
        display->setColor(WHITE);
        display->setFont(FONT_SMALL);
        display->setTextAlignment(TEXT_ALIGN_CENTER);
        display->drawString(w / 2 + x, barY + 2 + y, msg.c_str());
        display->setColor(WHITE);
    };

    screen->startAlert(statusFrame);
    showingRaamsesOverlay = true;
}
#endif

// ─── HTTP helpers ─────────────────────────────────────────────

static String gatewayGet(const char *path) {
    HTTPClient http;
    String url = "http://" + String(RAAMSES_GATEWAY_HOST) + ":" + String(RAAMSES_GATEWAY_PORT) + String(path);
    http.begin(url);
    http.setTimeout(5000);
    int code = http.GET();
    String body = (code > 0) ? http.getString() : "";
    http.end();
    return body;
}

static String gatewayPost(const char *path, const String &jsonBody) {
    HTTPClient http;
    String url = "http://" + String(RAAMSES_GATEWAY_HOST) + ":" + String(RAAMSES_GATEWAY_PORT) + String(path);
    http.begin(url);
    http.addHeader("Content-Type", "application/json");
    http.setTimeout(5000);
    int code = http.POST(jsonBody);
    String body = (code > 0) ? http.getString() : "";
    http.end();
    return body;
}

// ─── Mesh protocol (variable-length, private channel) ─────────

void RaamsesModule::sendMeshPacket(const uint8_t *payload, uint8_t size)
{
    meshtastic_MeshPacket *p = allocDataPacket();
    if (!p) {
        LOG_WARN("Raamses: could not allocate mesh packet");
        return;
    }
    p->decoded.payload.size = size;
    memcpy(p->decoded.payload.bytes, payload, size);
    p->to = NODENUM_BROADCAST;
    p->want_ack = false;
    p->channel = RAAMSES_CHANNEL_INDEX;
    service->sendToMesh(p);
}

void RaamsesModule::sendAlert(uint8_t count) {
    uint8_t buf[8];
    uint8_t sz = RaamsesProto::buildAlert(buf, count);
    sendMeshPacket(buf, sz);
    LOG_INFO("Raamses: mesh sent ALERT count=%u", count);
}

void RaamsesModule::sendAck(uint8_t pid) {
    uint8_t buf[8];
    uint8_t sz = RaamsesProto::buildAck(buf, pid);
    sendMeshPacket(buf, sz);
    LOG_INFO("Raamses: mesh sent ACK pager=0x%02X", pid);
}

void RaamsesModule::sendClear(uint8_t count) {
    uint8_t buf[8];
    uint8_t sz = RaamsesProto::buildClear(buf, count);
    sendMeshPacket(buf, sz);
    LOG_INFO("Raamses: mesh sent CLEAR count=%u", count);
}

void RaamsesModule::sendHeartbeat() {
    uint8_t buf[16];
    uint8_t sz = RaamsesProto::buildHeartbeat(buf, nodeId, RaamsesProto::OK);
    sendMeshPacket(buf, sz);
}

void RaamsesModule::sendRegister() {
    uint8_t buf[16];
    uint8_t dt;
#if defined(HELTEC_V3)
    dt = RaamsesProto::HELTEC_V3;
#elif defined(HELTEC_V4)
    dt = RaamsesProto::HELTEC_V4;
#elif defined(THINKNODE_M2)
    dt = RaamsesProto::THINKNODE_M2;
#else
    dt = 0x00;
#endif
    uint8_t sz = RaamsesProto::buildRegister(buf, nodeId, dt, fwVersion);
    sendMeshPacket(buf, sz);
    LOG_INFO("Raamses: mesh sent REGISTER nodeId=%08X type=%s ver=%u.%u",
             nodeId, RaamsesProto::deviceTypeName(dt), fwVersion >> 8, fwVersion & 0xFF);
}

// ─── Receive ─────────────────────────────────────────────────

ProcessMessage RaamsesModule::handleReceived(const meshtastic_MeshPacket &mp)
{
    if (mp.from == nodeDB->getNodeNum())
        return ProcessMessage::CONTINUE;

    const uint8_t *buf = mp.decoded.payload.bytes;
    uint8_t size = mp.decoded.payload.size;

    if (!RaamsesProto::validPacket(buf, size))
        return ProcessMessage::CONTINUE;

    uint8_t cmd = buf[0];
    uint8_t len = buf[1];
    const uint8_t *data = &buf[2];

    LOG_INFO("Raamses: mesh recv %s len=%u from 0x%08X",
             RaamsesProto::cmdName(cmd), len, mp.from);

    switch (cmd) {

    case RaamsesProto::ALERT: {
        if (len < 1) return ProcessMessage::CONTINUE;
        uint32_t now = millis();
        if (now - lastMeshAlertAt < 2000) {
            LOG_DEBUG("Raamses: mesh alert debounced");
            return ProcessMessage::CONTINUE;
        }
        if (!lastAlertState) {
            triggerLocalAlert("via LoRa mesh");
        }
        lastAlertState = true;
        lastMeshAlertAt = now;

        if (pagerId != RaamsesProto::BRIDGE) {
            sendAck(pagerId);
        }
        break;
    }

    case RaamsesProto::CLEAR:
        lastAlertState = false;
        ledFlashUntil = 0;
        digitalWrite(LED_PIN, LED_STATE_ON ? LOW : HIGH);
        statusMessage = "All systems OK";
#if HAS_SCREEN
        showStatusScreen();
#endif
        break;

    case RaamsesProto::BUZZ:
        if (len >= 1) flashLed(data[0] * 500);
        break;

    case RaamsesProto::ACK:
        if (len >= 1) LOG_INFO("Raamses: ACK from pager 0x%02X", data[0]);
        break;

    case RaamsesProto::REGISTER:
        if (len >= 3) {
            uint32_t remoteId;
            memcpy(&remoteId, data, 4);
            LOG_INFO("Raamses: REGISTER from node %08X type=%s",
                     remoteId, RaamsesProto::deviceTypeName(data[4]));
        }
        break;

    case RaamsesProto::HEARTBEAT:
        if (len >= 5) {
            uint32_t remoteId;
            memcpy(&remoteId, data, 4);
            LOG_DEBUG("Raamses: HEARTBEAT from %08X status=%u", remoteId, data[4]);
        }
        break;

    default:
        break;
    }

    return ProcessMessage::CONTINUE;
}

bool RaamsesModule::wantPacket(const meshtastic_MeshPacket *p)
{
    // Filter by port and minimum valid header size
    return p->decoded.portnum == ourPortNum &&
           p->decoded.payload.size >= RaamsesProto::HEADER_SIZE;
}

// ─── Local alert ──────────────────────────────────────────────

void RaamsesModule::triggerLocalAlert(const char *source)
{
    LOG_WARN("Raamses: AGENT NEEDS HELP (%s)", source);
    statusMessage = source;
#if HAS_SCREEN
    drawAlertOnScreen(source);
#endif
    flashLed(5000);
}

// ─── LED flash ────────────────────────────────────────────────

void RaamsesModule::flashLed(uint32_t durationMs)
{
    ledFlashUntil = millis() + durationMs;
    ledFlashPhase = 0;
}

// ─── LoRa fallback ────────────────────────────────────────────

void RaamsesModule::fallbackToLoRa()
{
    WiFi.disconnect();
    wifiConnected = false;
    pagerId = 0x01;  // node mode
    statusMessage = "LoRa mesh mode";
#if HAS_SCREEN
    showStatusScreen();
#endif
    state = LORA_REGISTER;
    stateSince = millis();
    LOG_INFO("Raamses: falling back to LoRa-only mode, nodeId=%08X", nodeId);
}

// ─── OSThread ─────────────────────────────────────────────────

RaamsesModule::RaamsesModule()
    : concurrency::OSThread("Raamses"),
      SinglePortModule("Raamses", meshtastic_PortNum_PRIVATE_APP)
{
    raamsesModule = this;
    state = STARTUP;
    stateSince = millis();
    statusMessage = "Starting up...";
    nodeId = nodeDB->getNodeNum();
}

int32_t RaamsesModule::runOnce()
{
    uint32_t now = millis();

    // ── LED flash pattern ─────────────────────────────────
    if (ledFlashUntil) {
        if (now < ledFlashUntil) {
            uint32_t period = lastAlertState ? 250 : 500;
            bool phase = ((now / period) % 2) == 0;
            if (phase != (bool)ledFlashPhase) {
                ledFlashPhase = (int)phase;
                digitalWrite(LED_PIN, phase ? LED_STATE_ON : !LED_STATE_ON);
            }
        } else {
            digitalWrite(LED_PIN, LED_STATE_ON ? LOW : HIGH);
            ledFlashUntil = 0;
            ledFlashPhase = 0;
        }
        if (ledFlashUntil)
            return 100;
    }

    // ── Button check (toggle Raamses overlay / Meshtastic UI) ──
#ifdef BUTTON_PIN
    if (now - lastButtonCheck > 200) {
        bool btn = digitalRead(BUTTON_PIN);
        if (!btn && lastButtonState && (now - lastButtonCheck > 200)) {
            LOG_INFO("Raamses: button pressed — toggle overlay");
#if HAS_SCREEN
            if (showingRaamsesOverlay) {
                screen->endAlert();
                showingRaamsesOverlay = false;
            } else if (wifiConnected || state == LORA_ACTIVE || state == GATEWAY_ACTIVE) {
                showStatusScreen();
            }
#endif
        }
        lastButtonState = btn;
        lastButtonCheck = now;
    }
#endif

    // ── Refresh nodeId (available after nodeDB init) ────────
    if (nodeId == 0) {
        nodeId = nodeDB->getNodeNum();
    }

    switch (state) {

    // ════════════════════════════════════════════════════════
    case STARTUP: {
        if (!splashShown) {
#if HAS_SCREEN
            drawSplashOnScreen();
#endif
            splashShown = true;
            stateSince = now;
            pinMode(LED_PIN, OUTPUT);
            digitalWrite(LED_PIN, LED_STATE_ON ? LOW : HIGH);
#ifdef BUTTON_PIN
            pinMode(BUTTON_PIN, INPUT_PULLUP);
#endif
            flashLed(3000);
            LOG_INFO("Raamses: pager 0x%02X ready, nodeId=%08X, LED pin %d",
                     pagerId, nodeId, LED_PIN);
        }
        if (now - stateSince > 3000) {
#if HAS_SCREEN
            statusMessage = "Connecting WiFi...";
            showStatusScreen();
#endif
            state = WIFI_CONNECTING;
            stateSince = now;
            wifiRetries = 0;
        }
        return 200;
    }

    // ════════════════════════════════════════════════════════
    case WIFI_CONNECTING: {
        WiFi.mode(WIFI_STA);
        esp_wifi_set_max_tx_power(78);
        WiFi.begin(RAAMSES_WIFI_SSID, RAAMSES_WIFI_PASS);
        LOG_INFO("Raamses: connecting Wi-Fi %s (attempt %d)", RAAMSES_WIFI_SSID, wifiRetries + 1);

        uint32_t start = now;
        while (WiFi.status() != WL_CONNECTED) {
            if (millis() - start > 15000) {
                wifiRetries++;
                LOG_WARN("Raamses: Wi-Fi timeout (attempt %d of %d)",
                         wifiRetries, RAAMSES_WIFI_MAX_RETRIES);

                if (wifiRetries >= RAAMSES_WIFI_MAX_RETRIES) {
                    LOG_WARN("Raamses: max WiFi retries reached — falling back to LoRa");
                    fallbackToLoRa();
                    return 0;
                }

                statusMessage = "WiFi timeout — retrying";
                WiFi.disconnect();
                return 10000;
            }
            delay(200);
        }
        wifiConnected = true;
        pagerId = RaamsesProto::BRIDGE;
        LOG_INFO("Raamses: Wi-Fi up, IP=%s, BRIDGE mode", WiFi.localIP().toString().c_str());
        state = WIFI_CONNECTED;
        stateSince = now;
        return 0;
    }

    // ════════════════════════════════════════════════════════
    case WIFI_CONNECTED: {
        statusMessage = "Registering with gateway...";

        // Use Meshtastic node ID instead of efuse MAC
        String deviceId = "meshtastic_" + String(nodeId, HEX);
        String json = "{\"device_id\":\"" + deviceId +
                      "\",\"device_type\":\"" RAAMSES_DEVICE_TYPE
                      "\",\"schema_version\":\"1.0\",\"firmware_version\":\"" + optstr(APP_VERSION) + "\"}";
        String resp = gatewayPost("/register", json);

        if (resp.indexOf("\"accepted\"") > 0 || resp.indexOf("\"registered\"") > 0) {
            LOG_INFO("Raamses: gateway registered as %s", deviceId.c_str());
            statusMessage = "All systems OK";
            state = GATEWAY_ACTIVE;
            stateSince = now;
            lastHeartbeat = now;
            lastPoll = now + 600;
#if HAS_SCREEN
            showStatusScreen();
#endif
        } else {
            LOG_WARN("Raamses: registration failed, retry 5s");
            statusMessage = "Gateway registration failed";
            return 5000;
        }
        return 0;
    }

    // ════════════════════════════════════════════════════════
    case GATEWAY_ACTIVE: {
        if (!wifiConnected) {
            statusMessage = "WiFi disconnected — falling back to LoRa";
            fallbackToLoRa();
            return 0;
        }

        // Heartbeat
        if (now - lastHeartbeat >= 8000) {
            String deviceId = "meshtastic_" + String(nodeId, HEX);
            String hbResp = gatewayPost("/heartbeat",
                        "{\"device_id\":\"" + deviceId + "\",\"uptime_seconds\":" + String(millis()/1000) + "}");
            if (hbResp.length() == 0 || hbResp.indexOf("error") >= 0) {
                statusMessage = "Server unreachable";
            }
            lastHeartbeat = now;
        }

        // Poll
        if (now - lastPoll >= 5000) {
            String body = gatewayGet("/agents");
            lastPoll = now;

            if (body.length() == 0) {
                statusMessage = "No response from server";
            }

            bool needsHelp = false;
            if (body.length() > 0) {
                if (body.indexOf("\"needs_help\"") > 0 || body.indexOf("needs help") > 0 ||
                    body.indexOf("AGENT_NEEDS_HELP") > 0)
                    needsHelp = true;
                if (body.indexOf("\"status\":\"alert\"") > 0 || body.indexOf("\"status\": \"alert\"") > 0)
                    needsHelp = true;
            }

            if (needsHelp && !lastAlertState) {
                triggerLocalAlert("via gateway");
                alertCount++;
                sendAlert(alertCount);
                lastMeshAlertAt = now;
                lastAlertState = true;
            }
            if (!needsHelp && lastAlertState) {
                ledFlashUntil = 0;
                digitalWrite(LED_PIN, LED_STATE_ON ? LOW : HIGH);
                statusMessage = "All systems OK";
#if HAS_SCREEN
                showStatusScreen();
#endif
                sendClear(alertCount);
                lastAlertState = false;
            }

            // Periodic status update
            if (!lastAlertState && showingRaamsesOverlay && body.length() > 0) {
                if (statusMessage.find("No response") != std::string::npos ||
                    statusMessage.find("unreachable") != std::string::npos) {
                    statusMessage = "All systems OK";
#if HAS_SCREEN
                    showStatusScreen();
#endif
                }
            }
        }
        return 500;
    }

    // ════════════════════════════════════════════════════════
    case LORA_REGISTER: {
        // Send REGISTER on private channel, wait for ACK
        sendRegister();
        LOG_INFO("Raamses: sent LoRa REGISTER, waiting 2s for ACK");
        state = LORA_ACTIVE;
        stateSince = now;
        lastHeartbeat = now;
        return 2000;
    }

    // ════════════════════════════════════════════════════════
    case LORA_ACTIVE: {
        // Periodic HEARTBEAT every 30 seconds
        if (now - lastHeartbeat >= 30000) {
            sendHeartbeat();
            lastHeartbeat = now;
        }

        // If WiFi comes back, try to reconnect
        if (now - stateSince > 60000 && wifiRetries < RAAMSES_WIFI_MAX_RETRIES) {
            LOG_INFO("Raamses: attempting WiFi reconnect from LoRa mode");
            state = WIFI_CONNECTING;
            stateSince = now;
            return 0;
        }
        return 1000;
    }

    } // switch
    return 1000;
}

#endif // ARCH_ESP32 && HAS_RAAMSES
