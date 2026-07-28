#pragma once

#include "configuration.h"

#if defined(ARCH_ESP32) && defined(HAS_RAAMSES)

#include "RaamsesProto.h"
#include "SinglePortModule.h"
#include "concurrency/OSThread.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <string>

/**
 * RaamsesModule — agent alert display, LED flash, and LoRa mesh relay.
 *
 * Two modes from one firmware:
 *   BRIDGE: WiFi-connected, polls gateway HTTP, shows status screen, broadcasts on LoRa.
 *   NODE:   LoRa-only, listens for RaamsesProto packets, shows alerts on receipt.
 *
 * Protocol: 3-byte binary packets — see RaamsesProto.h.
 */
class RaamsesModule : private concurrency::OSThread, public SinglePortModule
{
    enum State {
        STARTUP,
        WIFI_CONNECTING,
        WIFI_CONNECTED,
        GATEWAY_ACTIVE,
    };

    State state = STARTUP;
    uint32_t stateSince = 0;
    uint32_t lastHeartbeat = 0;
    uint32_t lastPoll = 0;
    bool splashShown = false;
    bool lastAlertState = false;
    bool wifiConnected = false;
    uint32_t lastMeshAlertAt = 0;
    uint8_t alertCount = 0;       // rolling counter, wraps at 255
    uint8_t pagerId = 0x01;       // 0=bridge, 1-254=node; defaults to 1 unless set

    // LED flash state (replaces vibration motor)
    uint32_t ledFlashUntil = 0;
    int ledFlashPhase = 0;

    // Status bar
    std::string statusMessage;
    bool showingRaamsesOverlay = false;

    // Button debounce for Meshtastic toggle
    uint32_t lastButtonCheck = 0;
    bool lastButtonState = true;  // pull-up, so HIGH = released

  public:
    RaamsesModule();

    // Set this device's pager ID (0=bridge, 1-254=node)
    void setPagerId(uint8_t id) { pagerId = id; }
    uint8_t getPagerId() const { return pagerId; }

  protected:
    // OSThread
    virtual int32_t runOnce() override;

    // SinglePortModule
    virtual ProcessMessage handleReceived(const meshtastic_MeshPacket &mp) override;
    virtual bool wantPacket(const meshtastic_MeshPacket *p) override;

    // Send a RaamsesProto packet over LoRa
    void sendMeshPacket(const RaamsesProto::Packet &pkt);

    // Trigger local alert: screen + LED flash
    void triggerLocalAlert(const char *source);

    // LED flash: start flashing for durationMs
    void flashLed(uint32_t durationMs);

    // Status screen (persistent frame with bottom bar)
    void showStatusScreen();

#if HAS_SCREEN
    void drawAlertOnScreen(const char *msg);
    void drawSplashOnScreen();
#endif
};

extern RaamsesModule *raamsesModule;

#endif // ARCH_ESP32 && HAS_RAAMSES
