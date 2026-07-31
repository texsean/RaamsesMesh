#pragma once

#include "configuration.h"

#if defined(ARCH_ESP32) && defined(HAS_RAAMSES)

#include "RaamsesProto.h"
#include "SinglePortModule.h"
#include "concurrency/OSThread.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <string>
#include <vector>

// ─── Agent info (parsed from /agents JSON) ─────────────────────

struct AgentInfo {
    char name[16];
    bool alert;          // true = needs help
    bool online;

    AgentInfo() : name{0}, alert(false), online(true) {}
};

/**
 * RaamsesModule — agent alert display, LED flash, LoRa mesh relay.
 */
class RaamsesModule : private concurrency::OSThread, public SinglePortModule
{
    enum State {
        STARTUP,
        WIFI_CONNECTING,
        WIFI_CONNECTED,
        GATEWAY_ACTIVE,
        LORA_REGISTER,
        LORA_ACTIVE,
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
    uint8_t regRetries = 0;   // registration retries for WIFI_CONNECTED fallback

    // Sequence numbers
    uint16_t alertSeq = 0;
    uint16_t lastAlertSeq = 0;
    bool haveLastSeq = false;

    // LED flash state
    uint32_t ledFlashUntil = 0;
    int ledFlashPhase = 0;

    // Status bar
    std::string statusMessage;
    bool showingRaamsesOverlay = false;

    // Button debounce
    uint32_t lastButtonCheck = 0;
    bool lastButtonState = true;

    // LoRa identity
    uint32_t nodeId = 0;
    uint16_t fwVersion = 0x0100;

    // Agent data from server
    AgentInfo agents[4];
    uint8_t agentCount = 0;
    uint8_t agentAlertCount = 0;
    std::string agentDisplayText;  // pre-formatted for status screen

  public:
    RaamsesModule();

    void setPagerId(uint8_t id) { pagerId = id; }
    uint8_t getPagerId() const { return pagerId; }

  protected:
    virtual int32_t runOnce() override;
    virtual ProcessMessage handleReceived(const meshtastic_MeshPacket &mp) override;
    virtual bool wantPacket(const meshtastic_MeshPacket *p) override;

    // Mesh send
    void sendMeshPacket(const uint8_t *payload, uint8_t size);
    void sendAlert(uint8_t count, uint16_t seq);
    void sendAck(uint8_t pagerId);
    void sendClear(uint8_t count, uint16_t seq);
    void sendHeartbeat();
    void sendRegister();

    // Relay
    void relayRegisterToGateway(const uint8_t *data, uint8_t len);
    void relayHeartbeatToGateway(const uint8_t *data, uint8_t len);

    // Parse /agents JSON response
    void parseAgents(const String &body);

    // Alert + display
    void triggerLocalAlert(const char *source);
    void flashLed(uint32_t durationMs);
    void showStatusScreen();
    void fallbackToLoRa();

#if HAS_SCREEN
    void drawAlertOnScreen(const char *msg);
    void drawSplashOnScreen();
#endif
};

extern RaamsesModule *raamsesModule;

#endif // ARCH_ESP32 && HAS_RAAMSES
