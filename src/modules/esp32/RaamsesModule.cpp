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

// Payload for mesh alert — keep it short, LoRa packets are precious
const char RaamsesModule::ALERT_PAYLOAD[] = "RAAMSES_ALERT";

// ─── screen drawing helpers ───────────────────────────────────

#if HAS_SCREEN
void RaamsesModule::drawSplashOnScreen()
{
    if (!screen)
        return;
    auto *display = screen->getDisplayDevice();
    if (!display)
        return;

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
    if (!screen)
        return;
    auto *display = screen->getDisplayDevice();
    if (!display)
        return;

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
#endif // HAS_SCREEN

// ─── HTTP helpers ─────────────────────────────────────────────

static String gatewayGet(const char *path)
{
    HTTPClient http;
    String url = "http://" + String(RAAMSES_GATEWAY_HOST) + ":" + String(RAAMSES_GATEWAY_PORT) + String(path);
    http.begin(url);
    http.setTimeout(5000);
    int code = http.GET();
    String body = (code > 0) ? http.getString() : "";
    http.end();
    return body;
}

static String gatewayPost(const char *path, const String &jsonBody)
{
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

// ─── Mesh alert relay ─────────────────────────────────────────

void RaamsesModule::sendMeshAlert()
{
    meshtastic_MeshPacket *p = allocDataPacket();
    if (!p) {
        LOG_WARN("Raamses: could not allocate mesh packet for alert");
        return;
    }

    p->decoded.payload.size = strlen(ALERT_PAYLOAD);
    memcpy(p->decoded.payload.bytes, ALERT_PAYLOAD, p->decoded.payload.size);
    p->to = NODENUM_BROADCAST;
    p->want_ack = false; // fire and forget — every node should hear it

    service->sendToMesh(p);
    LOG_INFO("Raamses: mesh alert broadcast sent");
}

ProcessMessage RaamsesModule::handleReceived(const meshtastic_MeshPacket &mp)
{
    // Ignore our own packets (we already buzzed from the HTTP path)
    if (mp.from == nodeDB->getNodeNum()) {
        LOG_DEBUG("Raamses: ignoring own mesh alert");
        return ProcessMessage::CONTINUE;
    }

    // Debounce: if we just triggered an HTTP alert, don't double-buzz
    uint32_t now = millis();
    if (now - lastMeshAlertAt < 2000) {
        LOG_DEBUG("Raamses: mesh alert debounced (within 2s of last alert)");
        return ProcessMessage::CONTINUE;
    }

    LOG_INFO("Raamses: mesh alert received from node 0x%08x", mp.from);

    // Only trigger if we're not already in alert state
    if (!lastAlertState) {
        triggerLocalAlert("via LoRa mesh");
    }

    // Track the alert as active even if we debounced
    lastAlertState = true;
    lastMeshAlertAt = now;

    return ProcessMessage::CONTINUE;
}

bool RaamsesModule::wantPacket(const meshtastic_MeshPacket *p)
{
    // Only interested in our custom port with the alert payload
    if (p->decoded.portnum != ourPortNum)
        return false;
    if (p->decoded.payload.size != strlen(ALERT_PAYLOAD))
        return false;
    return memcmp(p->decoded.payload.bytes, ALERT_PAYLOAD, p->decoded.payload.size) == 0;
}

// ─── Local alert trigger ──────────────────────────────────────

void RaamsesModule::triggerLocalAlert(const char *msg)
{
    LOG_WARN("Raamses: AGENT NEEDS HELP — buzzing! (%s)", msg);
#if HAS_SCREEN
    drawAlertOnScreen(msg);
#endif
    buzzAlert(5000);
    lastAlertState = true;
}

// ─── OSThread lifecycle ───────────────────────────────────────

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

    // ── Buzzer PWM management (non-blocking) ─────────────────
    if (alertBuzzerUntil && now < alertBuzzerUntil) {
        bool phase = ((now / 500) % 2) == 0;
        bool changed = (phase != (bool)alertBuzzerPhase);
        if (changed) {
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

            LOG_INFO("Raamses: splash shown, pin %d configured", VIBRATION_MOTOR_PIN);
        }

        if (now - stateSince > 3000) {
            state = WIFI_CONNECTING;
            stateSince = now;
            LOG_INFO("Raamses: switching to Wi-Fi connect");
        }
        return 200;
    }

    case WIFI_CONNECTING: {
        WiFi.mode(WIFI_STA);
        esp_wifi_set_max_tx_power(78);
        WiFi.begin(RAAMSES_WIFI_SSID, RAAMSES_WIFI_PASS);

        LOG_INFO("Raamses: connecting to Wi-Fi SSID=%s", RAAMSES_WIFI_SSID);

        uint32_t start = now;
        while (WiFi.status() != WL_CONNECTED) {
            if (millis() - start > 15000) {
                LOG_WARN("Raamses: Wi-Fi timeout, retrying in 10 s");
                WiFi.disconnect();
                return 10000;
            }
            delay(200);
        }

        wifiConnected = true;
        LOG_INFO("Raamses: Wi-Fi connected, IP=%s (bridge mode active)", WiFi.localIP().toString().c_str());
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
        LOG_INFO("Raamses: register response: %s", resp.c_str());

        if (resp.indexOf("\"accepted\"") > 0 || resp.indexOf("\"registered\"") > 0) {
            LOG_INFO("Raamses: gateway registration accepted");
            state = GATEWAY_ACTIVE;
            stateSince = now;
            lastHeartbeat = now;
            lastPoll = now + 600; // offset for registration race
        } else {
            LOG_WARN("Raamses: registration failed, retrying in 5 s");
            return 5000;
        }
        return 0;
    }

    case GATEWAY_ACTIVE: {
        if (!wifiConnected) {
            // WiFi dropped — just listen on mesh
            state = GATEWAY_ACTIVE;
            return 5000;
        }

        // ── Heartbeat ──
        if (now - lastHeartbeat >= 8000) {
            String deviceId = "heltec-" + String((uint32_t)ESP.getEfuseMac(), HEX);
            String json = "{\"device_id\":\"" + deviceId + "\",\"uptime_seconds\":" + String(millis() / 1000) + "}";
            gatewayPost("/heartbeat", json);
            lastHeartbeat = now;
        }

        // ── Poll agents ──
        if (now - lastPoll >= 5000) {
            String body = gatewayGet("/agents");
            lastPoll = now;

            bool agentNeedsHelp = false;

            if (body.length() > 0) {
                if (body.indexOf("\"needs_help\"") > 0 || body.indexOf("needs help") > 0 ||
                    body.indexOf("AGENT_NEEDS_HELP") > 0) {
                    agentNeedsHelp = true;
                }
                if (body.indexOf("\"status\":\"alert\"") > 0 || body.indexOf("\"status\": \"alert\"") > 0) {
                    agentNeedsHelp = true;
                }
            }

            // Rising edge: HTTP alert detected
            if (agentNeedsHelp && !lastAlertState) {
                triggerLocalAlert("via gateway");

                // ── RELAY OVER LORA MESH ──
                sendMeshAlert();
                lastMeshAlertAt = now;
            }

            // Falling edge
            if (!agentNeedsHelp && lastAlertState) {
                LOG_INFO("Raamses: alert cleared");
                lastAlertState = false;
            }

            if (!agentNeedsHelp) {
                lastAlertState = false;
            }
        }

        return 500;
    }

    case ALERT:
        state = GATEWAY_ACTIVE;
        return 0;

    } // switch

    return 1000;
}

void RaamsesModule::buzzAlert(uint32_t durationMs)
{
    alertBuzzerUntil = millis() + durationMs;
    alertBuzzerPhase = 0;
}

#endif // ARCH_ESP32 && HAS_RAAMSES
