#include "configuration.h"

#if defined(ARCH_ESP32) && defined(HAS_RAAMSES)

#include "RaamsesModule.h"
#include "Default.h"
#include "MeshService.h"
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
    LOG_DEBUG("Raamses GET %s -> %d", path, code);
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
    LOG_DEBUG("Raamses POST %s -> %d  body=%s", path, code, jsonBody.c_str());
    return body;
}

// ─── OSThread lifecycle ───────────────────────────────────────

RaamsesModule::RaamsesModule()
    : concurrency::OSThread("Raamses")
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
        // 500ms on / 500ms off pattern
        bool phase = ((now / 500) % 2) == 0;
        bool changed = (phase != (bool)alertBuzzerPhase);
        if (changed) {
            alertBuzzerPhase = (int)phase;
            digitalWrite(VIBRATION_MOTOR_PIN, phase ? HIGH : LOW);
        }
        return 100; // check again soon
    } else if (alertBuzzerUntil && now >= alertBuzzerUntil) {
        digitalWrite(VIBRATION_MOTOR_PIN, LOW);
        alertBuzzerUntil = 0;
        alertBuzzerPhase = 0;
    }

    switch (state) {

    case STARTUP: {
        // Show splash for 3 seconds
        if (!splashShown) {
#if HAS_SCREEN
            drawSplashOnScreen();
#endif
            splashShown = true;
            stateSince = now;

            // Init buzzer pin
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
        // Increase WiFi power for reliable range
        esp_wifi_set_max_tx_power(78); // 19.5 dBm
        WiFi.begin(RAAMSES_WIFI_SSID, RAAMSES_WIFI_PASS);

        LOG_INFO("Raamses: connecting to Wi-Fi SSID=%s", RAAMSES_WIFI_SSID);

        uint32_t start = now;
        while (WiFi.status() != WL_CONNECTED) {
            if (millis() - start > 15000) {
                LOG_WARN("Raamses: Wi-Fi timeout, retrying in 10 s");
                WiFi.disconnect();
                return 10000; // retry
            }
            delay(200);
        }

        LOG_INFO("Raamses: Wi-Fi connected, IP=%s", WiFi.localIP().toString().c_str());
        state = WIFI_CONNECTED;
        stateSince = now;
        return 0; // advance immediately
    }

    case WIFI_CONNECTED: {
        // Register with gateway
        String deviceId = "heltec-" + String((uint32_t)ESP.getEfuseMac(), HEX);
        String json = "{\"device_id\":\"" + deviceId +
                      "\",\"device_type\":\"" RAAMSES_DEVICE_TYPE
                      "\",\"schema_version\":\"1.0\",\"firmware_version\":\"" + optstr(APP_VERSION) + "\"}";

        String resp = gatewayPost("/register", json);
        LOG_INFO("Raamses: register response: %s", resp.c_str());

        // Check if response contains "accepted":true or "registered"
        if (resp.indexOf("\"accepted\"") > 0 || resp.indexOf("\"registered\"") > 0) {
            LOG_INFO("Raamses: gateway registration accepted");
            state = GATEWAY_ACTIVE;
            stateSince = now;
            lastHeartbeat = now;
            lastPoll = now;
            // Delay first poll to avoid the 500ms registration indexing race
            lastPoll += 600; // offset poll so first one fires after the race window
        } else {
            LOG_WARN("Raamses: registration failed, retrying in 5 s");
            return 5000;
        }
        return 0;
    }

    case GATEWAY_ACTIVE: {
        // ── Heartbeat every 8 seconds ──
        if (now - lastHeartbeat >= 8000) {
            String deviceId = "heltec-" + String((uint32_t)ESP.getEfuseMac(), HEX);
            String json = "{\"device_id\":\"" + deviceId + "\",\"uptime_seconds\":" + String(millis() / 1000) + "}";
            gatewayPost("/heartbeat", json);
            lastHeartbeat = now;
        }

        // ── Poll agents for status changes ──
        if (now - lastPoll >= 5000) {
            String body = gatewayGet("/agents");
            lastPoll = now;

            // Simple string scan: look for "needs_help" or "needs help" in the response
            bool agentNeedsHelp = false;
            String alertMsg = "";

            if (body.length() > 0) {
                // Check for explicit alert field
                if (body.indexOf("\"needs_help\"") > 0 || body.indexOf("needs help") > 0 ||
                    body.indexOf("AGENT_NEEDS_HELP") > 0) {
                    agentNeedsHelp = true;
                    alertMsg = "Agent requires attention";
                }

                // Also check for status field containing "alert" or "error"
                if (body.indexOf("\"status\":\"alert\"") > 0 || body.indexOf("\"status\": \"alert\"") > 0) {
                    agentNeedsHelp = true;
                    alertMsg = "Agent alert status";
                }
            }

            // Rising edge: no alert → alert
            if (agentNeedsHelp && !lastAlertState) {
                LOG_WARN("Raamses: AGENT NEEDS HELP — buzzing!");
#if HAS_SCREEN
                drawAlertOnScreen(alertMsg.c_str());
#endif
                buzzAlert(5000); // buzz for 5 seconds
            }

            // Falling edge: alert cleared
            if (!agentNeedsHelp && lastAlertState) {
                LOG_INFO("Raamses: alert cleared");
            }

            lastAlertState = agentNeedsHelp;
        }

        return 500; // sleep half a second between checks
    }

    case ALERT:
        // Alert state managed by rising edge in GATEWAY_ACTIVE
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
