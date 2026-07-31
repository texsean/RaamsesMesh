// Raamses binary LoRa protocol — variable-length packets on private channel
//
// Wire format (every packet):
//   [0] cmd          — command byte (see Cmd enum)
//   [1] len          — payload length in bytes (0-255)
//   [2 .. len+1]     — payload (len bytes)
//
// Total overhead: 2 bytes header.  Max payload: 255 bytes.
// All packets are encrypted by Meshtastic's channel layer — no LRC needed.
//
// Commands:
//   0x01 ALERT      agent needs help.       payload: [count:1][seq:2]
//   0x02 ACK        acknowledge receipt.    payload: [pagerId:1]
//   0x03 CLEAR      alert resolved.         payload: [count:1][seq:2]
//   0x04 HEARTBEAT  periodic keepalive.     payload: [nodeId:4][status:1]
//   0x05 REGISTER   device registration.    payload: [nodeId:4][deviceType:1][fwVersion:2]
//   0x06 BUZZ       test buzzer/LED.        payload: [durationHalfSec:1]
//
// Device types (REGISTER payload byte 5):
//   0x01 = heltec_v3
//   0x02 = heltec_v4
//   0x03 = thinknode_m2
//
// Status byte (HEARTBEAT payload byte 5):
//   0x00 = OK
//   0x01 = WiFi disconnected (bridge only)
//   0x02 = gateway unreachable (bridge only)
//   0x03 = LoRa-only mode
//   0xFF = error

#pragma once

#include <cstdint>
#include <cstring>

namespace RaamsesProto {

// ── Command byte ────────────────────────────────────────────
enum Cmd : uint8_t {
    ALERT     = 0x01,  // agent needs help
    ACK       = 0x02,  // acknowledge receipt
    CLEAR     = 0x03,  // alert resolved
    HEARTBEAT = 0x04,  // periodic keepalive
    REGISTER  = 0x05,  // device registration
    BUZZ      = 0x06,  // test buzzer/LED
};

// ── Device types ────────────────────────────────────────────
enum DeviceType : uint8_t {
    DEVICE_HELTEC_V3    = 0x01,
    DEVICE_HELTEC_V4    = 0x02,
    DEVICE_THINKNODE_M2 = 0x03,
};

// ── Heartbeat status ────────────────────────────────────────
enum Status : uint8_t {
    STATUS_OK          = 0x00,
    WIFI_DISCONNECTED = 0x01,
    GATEWAY_UNREACH   = 0x02,
    LORA_ONLY         = 0x03,
    ERROR             = 0xFF,
};

// ── Special IDs ─────────────────────────────────────────────
enum Id : uint8_t {
    BRIDGE    = 0x00,  // WiFi-connected gateway device
    BROADCAST = 0xFF,  // all pagers
};

// ── Maximum payload size helpers ────────────────────────────
inline constexpr uint8_t PAYLOAD_ALERT     = 3;  // count(1) + seq(2)
inline constexpr uint8_t PAYLOAD_ACK       = 1;  // pagerId
inline constexpr uint8_t PAYLOAD_CLEAR     = 3;  // count(1) + seq(2)
inline constexpr uint8_t PAYLOAD_HEARTBEAT = 5;  // nodeId(4) + status(1)
inline constexpr uint8_t PAYLOAD_REGISTER  = 7;  // nodeId(4) + deviceType(1) + fwVersion(2)
inline constexpr uint8_t PAYLOAD_BUZZ      = 1;  // duration

// ── Minimum valid header size ───────────────────────────────
inline constexpr uint8_t HEADER_SIZE = 2;  // cmd + len

// ── Builders ────────────────────────────────────────────────
// Each fills `buf` with [cmd][len][payload...] and returns total size.

inline uint8_t buildAlert(uint8_t *buf, uint8_t count, uint16_t seq) {
    buf[0] = ALERT;
    buf[1] = 3;
    buf[2] = count;
    memcpy(&buf[3], &seq, 2);
    return 5;
}

inline uint8_t buildAck(uint8_t *buf, uint8_t pagerId) {
    buf[0] = ACK;
    buf[1] = 1;
    buf[2] = pagerId;
    return 3;
}

inline uint8_t buildClear(uint8_t *buf, uint8_t count, uint16_t seq) {
    buf[0] = CLEAR;
    buf[1] = 3;
    buf[2] = count;
    memcpy(&buf[3], &seq, 2);
    return 5;
}

inline uint8_t buildHeartbeat(uint8_t *buf, uint32_t nodeId, uint8_t status) {
    buf[0] = HEARTBEAT;
    buf[1] = 5;
    memcpy(&buf[2], &nodeId, 4);
    buf[6] = status;
    return 7;
}

inline uint8_t buildRegister(uint8_t *buf, uint32_t nodeId, uint8_t deviceType, uint16_t fwVersion) {
    buf[0] = REGISTER;
    buf[1] = 7;
    memcpy(&buf[2], &nodeId, 4);
    buf[5] = deviceType;
    memcpy(&buf[6], &fwVersion, 2);
    return 9;
}

inline uint8_t buildBuzz(uint8_t *buf, uint8_t halfSeconds) {
    buf[0] = BUZZ;
    buf[1] = 1;
    buf[2] = halfSeconds;
    return 3;
}

// ── Packet parser ──────────────────────────────────────────
// Returns true if buf[0..size-1] contains a valid Raamses packet header.
// A valid packet has at least 2 bytes and len matches remaining bytes.

inline bool validPacket(const uint8_t *buf, uint8_t size) {
    if (size < HEADER_SIZE) return false;
    uint8_t len = buf[1];
    return (HEADER_SIZE + len) == size;
}

// ── Human-readable ───────────────────────────────────────────
inline const char *cmdName(uint8_t cmd) {
    switch (cmd) {
    case ALERT:     return "ALERT";
    case ACK:       return "ACK";
    case CLEAR:     return "CLEAR";
    case HEARTBEAT: return "HEARTBEAT";
    case REGISTER:  return "REGISTER";
    case BUZZ:      return "BUZZ";
    default:        return "?";
    }
}

inline const char *deviceTypeName(uint8_t dt) {
    switch (dt) {
    case DEVICE_HELTEC_V3:    return "heltec_v3";
    case DEVICE_HELTEC_V4:    return "heltec_v4";
    case DEVICE_THINKNODE_M2: return "thinknode_m2";
    default:                  return "?";
    }
}

} // namespace RaamsesProto
