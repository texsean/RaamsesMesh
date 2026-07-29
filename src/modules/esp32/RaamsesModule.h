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
 * RaamsesModule — agent alert display, LED flash, LoRa mesh relay.
 *
 * Modes from one firmware:
 *   BRIDGE:  WiFi → HTTP register + poll gateway. Relays alerts over LoRa.
 *   LORA:    No WiFi → LoRa REGISTER + periodic HEARTBEAT on private channel.
 *
 * Protocol: variable-length binary — see RaamsesProto.h.
 */
class RaamsesModule : private concurrency::OSThread, public SinglePortModule
{
    enum State {
        STARTUP,
        WIFI_CONNECTING,
        WIFI_CONNECTED,
        GATEWAY_ACTIVE,
        LORA_REGISTER,      // sending REGISTER on private channel
        LORA_ACTIVE,        // periodic HEARTBEAT, listen for ALERT
    };

    State state = STARTUP;
    uint32_t stateSince = 0;
    uint32_t lastHeartbeat = 0;
    uint32_t lastPoll = 0;
    bool splashShown = false;
    bool lastAlertState = false;
    bool wifiConnected = false;
    uint32_t lastMeshAlertAt = 0;
    uint8_t alertCount = 0;
    uint8_t pagerId = 0x01;
    uint8_t wifiRetries = 0;

    // LED flash state
    uint32_t ledFlashUntil = 0;
    int ledFlashPhase = 0;

    // Status bar
    std::string statusMessage;
    bool showingRaamsesOverlay = false;

    // Button debounce
    uint32_t lastButtonCheck = 0;
    bool lastButtonState = true;

    // LoRa node identity (cached from nodeDB)
    uint32_t nodeId = 0;

    // Firmware version (for REGISTER)
    uint16_t fwVersion = 0x0100;  // v1.0

  public:
    RaamsesModule();

    void setPagerId(uint8_t id) { pagerId = id; }
    uint8_t getPagerId() const { return pagerId; }

  protected:
    virtual int32_t runOnce() override;
    virtual ProcessMessage handleReceived(const meshtastic_MeshPacket &mp) override;
    virtual bool wantPacket(const meshtastic_MeshPacket *p) override;

    // Send a variable-length Raamses packet on the private channel
    void sendMeshPacket(const uint8_t *payload, uint8_t size);

    // Legacy wrappers for specific packet types
    void sendAlert(uint8_t count);
    void sendAck(uint8_t pagerId);
    void sendClear(uint8_t count);
    void sendHeartbeat();
    void sendRegister();

    void triggerLocalAlert(const char *source);
    void flashLed(uint32_t durationMs);
    void showStatusScreen();

    // Fall back to LoRa-only mode after WiFi fails
    void fallbackToLoRa();

#if HAS_SCREEN
    void drawAlertOnScreen(const char *msg);
    void drawSplashOnScreen();
#endif
};

extern RaamsesModule *raamsesModule;

#endif // ARCH_ESP32 && HAS_RAAMSES
