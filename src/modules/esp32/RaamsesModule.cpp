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
    auto *display = screen->getDisplayDevice();
    if (!display) return;
    display->clear();
    display->setFont(FONT_LARGE);
    display->setTextAlignment(TEXT_ALIGN_CENTER);
    display->drawString(display->getWidth() / 2, 10, "RAAMSES");
    display->setFont(FONT_SMALL);
    display->drawString(display->getWidth() / 2, 40, "agent alert console");
    display->display();
}

void RaamsesModule::drawAlertOnScreen(const char *msg)
{
    if (!screen) return;
    auto *display = screen->getDisplayDevice();
    if (!display) return;
    display->clear();
    display->setFont(FONT_MEDIUM);
    display->setTextAlignment(TEXT_ALIGN_CENTER);
    display->drawString(display->getWidth() / 2, 10, "AGENT NEEDS");
    display->setFont(FONT_LARGE);
    display->drawString(display->getWidth() / 2, 30, "HELP!");
    if (msg && msg[0]) {
        display->setFont(FONT_SMALL);
        display->drawString(display->getWidth() / 2, 50, msg);
    }
    display->display();
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
        break;

    case RaamsesProto::BUZZ:
        handleBuzz(pkt->data);
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
    buzzAlert(5000);
}

void RaamsesModule::handleBuzz(uint8_t halfSeconds)
{
    uint32_t ms = halfSeconds * 500;
    LOG_INFO("Raamses: test buzz for %u ms", ms);
    buzzAlert(ms);
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

    // ── Buzzer PWM ────────────────────────────────────────
    if (alertBuzzerUntil && now < alertBuzzerUntil) {
        bool phase = ((now / 500) % 2) == 0;
        if (phase != (bool)alertBuzzerPhase) {
            alertBuzzerPhase = (int)phase;
            digitalWrite(VIBRATION_MOTOR_PIN, phase ? HIGH : LOW);
        }
        return 100;
    } else if (alertBuzzerUntil && now >= alertBuzzerUntil) {
        digitalWrite(VIBRATION_MOTOR_PIN, LOW);
        alertBuzzerUntil = 0;
        alertBuzzerPhase = 0;
    }

    switch (state) {

    case STARTUP: {
        if (!splashShown) {
#if HAS_SCREEN
            drawSplashOnScreen();
#endif
            splashShown = true;
            stateSince = now;
            pinMode(VIBRATION_MOTOR_PIN, OUTPUT);
            digitalWrite(VIBRATION_MOTOR_PIN, LOW);
            LOG_INFO("Raamses: pager 0x%02X ready, pin %d", pagerId, VIBRATION_MOTOR_PIN);
        }
        if (now - stateSince > 3000) {
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
                // Alert cleared — broadcast CLEAR
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

void RaamsesModule::buzzAlert(uint32_t durationMs)
{
    alertBuzzerUntil = millis() + durationMs;
    alertBuzzerPhase = 0;
}

#endif // ARCH_ESP32 && HAS_RAAMSES
