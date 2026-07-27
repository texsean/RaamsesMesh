#pragma once

#include "configuration.h"

#if defined(ARCH_ESP32) && defined(HAS_RAAMSES)

#include "concurrency/OSThread.h"
#include <WiFi.h>
#include <HTTPClient.h>

/**
 * RaamsesModule — agent alert display & haptic feedback for Meshtastic Heltec V3.
 *
 * Startup: draws "RAAMSES" on the SSD1306 OLED for a few seconds, then
 * falls through to the normal Meshtastic UI.  Background thread connects
 * to the Raamses gateway (HTTP on port 8765), registers this device,
 * sends periodic heartbeats, and polls for agent status.  When any agent
 * transitions to "needs help" the vibration motor on VIBRATION_MOTOR_PIN
 * is pulsed and an alert banner is drawn on screen.
 */
class RaamsesModule : private concurrency::OSThread
{
    enum State {
        STARTUP,          // showing "RAAMSES" splash
        WIFI_CONNECTING,  // connecting to WiFi STA
        WIFI_CONNECTED,   // WiFi up, registering with gateway
        GATEWAY_ACTIVE,   // polling gateway, normal operation
        ALERT,            // agent needs help — buzzing
    };

    State state = STARTUP;
    uint32_t stateSince = 0;
    uint32_t lastHeartbeat = 0;
    uint32_t lastPoll = 0;
    bool splashShown = false;
    bool lastAlertState = false;
    uint32_t alertBuzzerUntil = 0;
    int alertBuzzerPhase = 0;

    // Gateway HTTP helpers
    String gatewayGet(const char *path);
    String gatewayPost(const char *path, const String &jsonBody);
    void buzzAlert(uint32_t durationMs);

  public:
    RaamsesModule();

  protected:
    virtual int32_t runOnce() override;

#if HAS_SCREEN
    virtual bool wantUIFrame() override { return false; }
    // Custom drawing called directly — not via the UI frame system
    void drawAlertOnScreen(const char *msg);
    void drawSplashOnScreen();
#endif
};

extern RaamsesModule *raamsesModule;

#endif // ARCH_ESP32 && HAS_RAAMSES
