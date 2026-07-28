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

    // Custom splash frame — shows for ~3s during STARTUP, then drops back to normal UI
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

    // Persistent alert frame — stays until endAlert() is called
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
    // Ignore own packets
    if (mp.from == nodeDB->getNodeNum())
        return ProcessMessage::CONTINUE;

    auto *pkt = reinterpret_cast<const RaamsesProto::Packet *>(mp.decoded.payload.bytes);

    // Validate
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

        // Send ACK back to bridge (if we're not the bridge)
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
#if HAS_SCREEN
        screen->endAlert();
#endif
        break;

    case RaamsesProto::BUZZ:
        flashLed(pkt->data * 500);  // half-seconds → ms LED flash
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
#if HAS_SCREEN
    drawAlertOnScreen(source);
#endif
    flashLed(5000);  // 5 seconds of LED flashing for alert
}

// ─── LED flash patterns ───────────────────────────────────────

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
}

int32_t RaamsesModule::runOnce()
{
    uint32_t now = millis();

    // ── LED flash pattern ─────────────────────────────────
    // Patterns:
    //   Alert active:       fast blink — 250ms on / 250ms off
    //   Splash/startup:     slow blink — 500ms on / 500ms off
    //   Normal / cleared:   LED off

    if (ledFlashUntil) {
        if (now < ledFlashUntil) {
            // Fast blink during alert (250ms period)
            uint32_t period = lastAlertState ? 250 : 500;
            bool phase = ((now / period) % 2) == 0;
            if (phase != (bool)ledFlashPhase) {
                ledFlashPhase = (int)phase;
                digitalWrite(LED_PIN, phase ? LED_STATE_ON : !LED_STATE_ON);
            }
        } else {
            // Flash duration expired — turn LED off
            digitalWrite(LED_PIN, LED_STATE_ON ? LOW : HIGH);
            ledFlashUntil = 0;
            ledFlashPhase = 0;
        }
        // Fast poll while LED is flashing
        if (ledFlashUntil)
            return 100;
    }

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
            // Slow blink during splash
            flashLed(3000);
            LOG_INFO("Raamses: pager 0x%02X ready, LED pin %d", pagerId, LED_PIN);
        }
        if (now - stateSince > 3000) {
#if HAS_SCREEN
            screen->endAlert(); // dismiss splash, hand back to normal UI
#endif
            state = WIFI_CONNECTING;
            stateSince = now;
        }
        return 200;
    }

    case WIFI_CONNECTING: {
        WiFi.mode(WIFI_STA);
        esp_wifi_set_max_tx_power(78);
        WiFi.begin(RAAMSES_WIFI_SSID, RAAMSES_WIFI_PASS);
        LOG_INFO("Raamses: connecting Wi-Fi %s", RAAMSES_WIFI_SSID);

        uint32_t start = now;
        while (WiFi.status() != WL_CONNECTED) {
            if (millis() - start > 15000) {
                LOG_WARN("Raamses: Wi-Fi timeout, retrying in 10s");
                WiFi.disconnect();
                return 10000;
            }
            delay(200);
        }
        wifiConnected = true;
        pagerId = RaamsesProto::BRIDGE; // we're the bridge
        LOG_INFO("Raamses: Wi-Fi up, IP=%s, BRIDGE mode", WiFi.localIP().toString().c_str());
        state = WIFI_CONNECTED;
        stateSince = now;
        return 0;
    }

    case WIFI_CONNECTED: {
        String deviceId = "heltec-" + String((uint32_t)ESP.getEfuseMac(), HEX);
        String json = "{\"device_id\":\"" + deviceId +
                      "\",\"device_type\":\"" RAAMSES_DEVICE_TYPE
                      "\",\"schema_version\":\"1.0\",\"firmware_version\":\"" + optstr(APP_VERSION) + "\"}";
        String resp = gatewayPost("/register", json);

        if (resp.indexOf("\"accepted\"") > 0 || resp.indexOf("\"registered\"") > 0) {
            LOG_INFO("Raamses: gateway registered");
            state = GATEWAY_ACTIVE;
            stateSince = now;
            lastHeartbeat = now;
            lastPoll = now + 600;
        } else {
            LOG_WARN("Raamses: registration failed, retry 5s");
            return 5000;
        }
        return 0;
    }

    case GATEWAY_ACTIVE: {
        if (!wifiConnected) {
            return 5000;
        }

        // Heartbeat
        if (now - lastHeartbeat >= 8000) {
            String deviceId = "heltec-" + String((uint32_t)ESP.getEfuseMac(), HEX);
            gatewayPost("/heartbeat",
                        "{\"device_id\":\"" + deviceId + "\",\"uptime_seconds\":" + String(millis()/1000) + "}");
            lastHeartbeat = now;
        }

        // Poll
        if (now - lastPoll >= 5000) {
            String body = gatewayGet("/agents");
            lastPoll = now;

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
                // Alert cleared — stop LED, broadcast CLEAR, dismiss display
                ledFlashUntil = 0;
                digitalWrite(LED_PIN, LED_STATE_ON ? LOW : HIGH);
#if HAS_SCREEN
                screen->endAlert();
#endif
                auto pkt = RaamsesProto::clear(alertCount);
                sendMeshPacket(pkt);
                lastAlertState = false;
            }
        }
        return 500;
    }

    } // switch
    return 1000;
}

#endif // ARCH_ESP32 && HAS_RAAMSES
