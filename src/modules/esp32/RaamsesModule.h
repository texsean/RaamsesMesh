#pragma once

#include "configuration.h"

#if defined(ARCH_ESP32) && defined(HAS_RAAMSES)

#include "RaamsesProto.h"
#include "SinglePortModule.h"
#include "concurrency/OSThread.h"
#include <WiFi.h>
#include <HTTPClient.h>

/**
 * RaamsesModule — agent alert display, haptic feedback, and LoRa mesh relay.
 *
 * Two modes from one firmware:
 *   BRIDGE: WiFi-connected, polls gateway HTTP, buzzes + broadcasts on LoRa.
 *   NODE:   LoRa-only, listens for RaamsesProto packets, buzzes on receipt.
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
    uint32_t alertBuzzerUntil = 0;
    int alertBuzzerPhase = 0;
    bool wifiConnected = false;
    uint32_t lastMeshAlertAt = 0;
    uint8_t alertCount = 0;       // rolling counter, wraps at 255
    uint8_t pagerId = 0x01;       // 0=bridge, 1-254=node; defaults to 1 unless set

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

    // Trigger local buzz + screen
    void triggerLocalAlert(const char *source);

    // Test buzz (called by BUZZ command from mesh)
    void handleBuzz(uint8_t halfSeconds);

    void buzzAlert(uint32_t durationMs);

#if HAS_SCREEN
    void drawAlertOnScreen(const char *msg);
    void drawSplashOnScreen();
#endif
};

extern RaamsesModule *raamsesModule;

#endif // ARCH_ESP32 && HAS_RAAMSES
