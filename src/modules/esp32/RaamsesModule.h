#pragma once

#include "configuration.h"

#if defined(ARCH_ESP32) && defined(HAS_RAAMSES)

#include "SinglePortModule.h"
#include "concurrency/OSThread.h"
#include <WiFi.h>
#include <HTTPClient.h>

/**
 * RaamsesModule — agent alert display, haptic feedback, and LoRa mesh relay.
 *
 * Two operating modes in one firmware:
 *   1. BRIDGE mode: connected to WiFi, polls the Raamses gateway via HTTP.
 *      When an alert is detected, buzzes locally AND broadcasts via LoRa mesh.
 *   2. NODE mode: listens on the LoRa mesh for Raamses alert packets.
 *      When received, buzzes and displays the alert — no WiFi needed.
 *
 * A single device can be both BRIDGE and NODE simultaneously: if the
 * WiFi-connected unit detects an alert, it buzzes immediately (HTTP path)
 * and also forwards it to every LoRa node in range.
 */
class RaamsesModule : private concurrency::OSThread, public SinglePortModule
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
    bool wifiConnected = false;     // true when we have WiFi (bridge mode active)
    uint32_t lastMeshAlertAt = 0;   // debounce: ignore mesh alerts shortly after HTTP alert

    static const char ALERT_PAYLOAD[];

  public:
    RaamsesModule();

  protected:
    // OSThread
    virtual int32_t runOnce() override;

    // SinglePortModule — receive mesh alert packets
    virtual ProcessMessage handleReceived(const meshtastic_MeshPacket &mp) override;
    virtual bool wantPacket(const meshtastic_MeshPacket *p) override;

    // Send alert over LoRa mesh
    void sendMeshAlert();

    // Trigger local buzz + screen
    void triggerLocalAlert(const char *msg);

    void buzzAlert(uint32_t durationMs);

#if HAS_SCREEN
    void drawAlertOnScreen(const char *msg);
    void drawSplashOnScreen();
#endif
};

extern RaamsesModule *raamsesModule;

#endif // ARCH_ESP32 && HAS_RAAMSES
