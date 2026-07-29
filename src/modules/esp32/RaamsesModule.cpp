#include "configuration.h"

#if defined(ARCH_ESP32) && defined(HAS_RAAMSES)

#include "RaamsesModule.h"
#include "MeshService.h"
#include "Router.h"
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

    // Capture a copy of statusMessage for the frame callback
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
        display->setColor(WHITE); // restore
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

// ─── Mesh protocol ────────────────────────────────────────────

void RaamsesModule::sendMeshPacket(const RaamsesProto::Packet &pkt)
{
    meshtastic_MeshPacket *p = allocDataPacket();
    if (!p) {
        LOG_WARN("Raamses: could not allocate mesh packet");
        return;
    }
    p->decoded.payload.size = sizeof(RaamsesProto::Packet);
    memcpy(p->decoded.payload.bytes, &pkt, sizeof(RaamsesProto::Packet));
    p->to = NODENUM_BROADCAST;
    p->want_ack = false;
    service->sendToMesh(p);
    LOG_INFO("Raamses: mesh sent %s data=0x%02X lrc=0x%02X",
             RaamsesProto::cmdName(pkt.cmd), pkt.data, pkt.lrc);
}

ProcessMessage RaamsesModule::handleReceived(const meshtastic_MeshPacket &mp)
{
    if (mp.from == nodeDB->getNodeNum())
        return ProcessMessage::CONTINUE;

    auto *pkt = reinterpret_cast<const RaamsesProto::Packet *>(mp.decoded.payload.bytes);

    if (mp.decoded.payload.size != sizeof(RaamsesProto::Packet))
        return ProcessMessage::CONTINUE;
    if (!pkt->valid()) {
        LOG_WARN("Raamses: mesh packet LRC mismatch (got 0x%02X expected 0x%02X)",
                 pkt->lrc, pkt->cmd ^ pkt->data);
        return ProcessMessage::CONTINUE;
    }

    LOG_INFO("Raamses: mesh recv %s data=0x%02X from 0x%08X",
             RaamsesProto::cmdName(pkt->cmd), pkt->data, mp.from);

    switch (pkt->cmd) {

    case RaamsesProto::ALERT: {
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
            auto ackPkt = RaamsesProto::ack(pagerId);
            sendMeshPacket(ackPkt);
        }
        break;
    }

    case RaamsesProto::CLEAR:
        LOG_INFO("Raamses: alert cleared via mesh");
        lastAlertState = false;
        ledFlashUntil = 0;
        digitalWrite(LED_PIN, LED_STATE_ON ? LOW : HIGH);
        statusMessage = "All systems OK";
#if HAS_SCREEN
        showStatusScreen();
#endif
        break;

    case RaamsesProto::BUZZ:
        flashLed(pkt->data * 500);
        break;

    case RaamsesProto::ACK:
        LOG_INFO("Raamses: ACK from pager 0x%02X", pkt->data);
        break;

    case RaamsesProto::IDENTIFY:
        LOG_INFO("Raamses: pager 0x%02X identified on mesh", pkt->data);
        break;

    default:
        break;
    }

    return ProcessMessage::CONTINUE;
}

bool RaamsesModule::wantPacket(const meshtastic_MeshPacket *p)
{
    return p->decoded.portnum == ourPortNum &&
           p->decoded.payload.size == sizeof(RaamsesProto::Packet);
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

// ─── OSThread ─────────────────────────────────────────────────

RaamsesModule::RaamsesModule()
    : concurrency::OSThread("Raamses"),
      SinglePortModule("Raamses", meshtastic_PortNum_PRIVATE_APP)
{
    raamsesModule = this;
    state = STARTUP;
    stateSince = millis();
    statusMessage = "Starting up...";
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
        // Button pressed: LOW (pull-up) transition
        if (!btn && lastButtonState && (now - lastButtonCheck > 200)) {
            LOG_INFO("Raamses: button pressed — toggle overlay");
#if HAS_SCREEN
            if (showingRaamsesOverlay) {
                screen->endAlert();
                showingRaamsesOverlay = false;
            } else if (wifiConnected || state >= WIFI_CONNECTED) {
                showStatusScreen();
            }
#endif
        }
        lastButtonState = btn;
        lastButtonCheck = now;
    }
#endif

    switch (state) {

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
            LOG_INFO("Raamses: pager 0x%02X ready, LED pin %d", pagerId, LED_PIN);
        }
        if (now - stateSince > 3000) {
            // Smooth transition: show status frame directly (never expose Meshtastic UI)
#if HAS_SCREEN
            showStatusScreen();
#endif
            state = WIFI_CONNECTING;
            stateSince = now;
        }
        return 200;
    }

    case WIFI_CONNECTING: {
        statusMessage = "Connecting WiFi...";
        WiFi.mode(WIFI_STA);
        esp_wifi_set_max_tx_power(78);
        WiFi.begin(RAAMSES_WIFI_SSID, RAAMSES_WIFI_PASS);
        LOG_INFO("Raamses: connecting Wi-Fi %s", RAAMSES_WIFI_SSID);

        uint32_t start = now;
        while (WiFi.status() != WL_CONNECTED) {
            if (millis() - start > 15000) {
                LOG_WARN("Raamses: Wi-Fi timeout, retrying in 10s");
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

    case WIFI_CONNECTED: {
        statusMessage = "Registering with gateway...";
        String deviceId = "heltec-" + String((uint32_t)ESP.getEfuseMac(), HEX);
        String json = "{\"device_id\":\"" + deviceId +
                      "\",\"device_type\":\"" RAAMSES_DEVICE_TYPE
                      "\",\"schema_version\":\"1.0\",\"firmware_version\":\"" + optstr(APP_VERSION) + "\"}";
        String resp = gatewayPost("/register", json);

        if (resp.indexOf("\"accepted\"") > 0 || resp.indexOf("\"registered\"") > 0) {
            LOG_INFO("Raamses: gateway registered");
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

    case GATEWAY_ACTIVE: {
        if (!wifiConnected) {
            statusMessage = "WiFi disconnected";
            return 5000;
        }

        // Heartbeat
        if (now - lastHeartbeat >= 8000) {
            String deviceId = "heltec-" + String((uint32_t)ESP.getEfuseMac(), HEX);
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
                auto pkt = RaamsesProto::alert(alertCount);
                sendMeshPacket(pkt);
                lastMeshAlertAt = now;
                lastAlertState = true;
            }
            if (!needsHelp && lastAlertState) {
                // Alert cleared — stop LED, broadcast CLEAR, back to status
                ledFlashUntil = 0;
                digitalWrite(LED_PIN, LED_STATE_ON ? LOW : HIGH);
                statusMessage = "All systems OK";
#if HAS_SCREEN
                showStatusScreen();
#endif
                auto pkt = RaamsesProto::clear(alertCount);
                sendMeshPacket(pkt);
                lastAlertState = false;
            }

            // Periodic status bar update (even when no state change)
            if (!lastAlertState && showingRaamsesOverlay && body.length() > 0) {
                // Gateway responsive — status is OK
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

    } // switch
    return 1000;
}

#endif // ARCH_ESP32 && HAS_RAAMSES
