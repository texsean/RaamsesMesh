// Raamses compact binary LoRa protocol — 3 bytes per packet
//
// Packet format:
//   [0] command    — message type (see RaamsesCmd below)
//   [1] data       — context-dependent (alert ID, pager ID, etc.)
//   [2] lrc        — XOR checksum of bytes 0-1
//
// Total: 3 bytes.  Fits in a single LoRa airframe with room to spare.
//
// Command reference:
//   0x01 ALERT     — agent needs help.  data = alert count (mod 256)
//   0x02 ACK       — pager acknowledges alert.  data = pager ID (0=bridge, 1-254=node)
//   0x03 CLEAR     — alert resolved.  data = alert count
//   0x04 PING      — heartbeat / keepalive.  data = pager ID
//   0x05 IDENTIFY  — pager announces itself.  data = pager ID
//   0x06 BUZZ      — test buzz.  data = duration in 500ms units
//
// Pager IDs:
//   0x00 = bridge (WiFi-connected gateway device)
//   0x01-0xFE = LoRa-only nodes (configured per device)
//   0xFF = broadcast (all pagers)

#pragma once

#include <cstdint>

namespace RaamsesProto {

// ── Command byte ────────────────────────────────────────────
enum Cmd : uint8_t {
    ALERT    = 0x01,  // agent needs help
    ACK      = 0x02,  // acknowledge receipt
    CLEAR    = 0x03,  // alert resolved
    PING     = 0x04,  // heartbeat / keepalive
    IDENTIFY = 0x05,  // pager announces itself
    BUZZ     = 0x06,  // test buzz
};

// ── Special IDs ─────────────────────────────────────────────
enum Id : uint8_t {
    BRIDGE    = 0x00,  // WiFi-connected gateway device
    BROADCAST = 0xFF,  // all pagers
};

// ── Packet structure (3 bytes) ──────────────────────────────
struct Packet {
    uint8_t cmd;   // command byte
    uint8_t data;  // context-dependent
    uint8_t lrc;   // XOR of cmd ^ data

    bool valid() const {
        return lrc == (cmd ^ data);
    }

    void seal() {
        lrc = cmd ^ data;
    }
} __attribute__((packed));

static_assert(sizeof(Packet) == 3, "Packet must be exactly 3 bytes");

// ── Builders ────────────────────────────────────────────────
inline Packet alert(uint8_t count) {
    Packet p = {ALERT, count, 0};
    p.seal();
    return p;
}

inline Packet ack(uint8_t pagerId) {
    Packet p = {ACK, pagerId, 0};
    p.seal();
    return p;
}

inline Packet clear(uint8_t count) {
    Packet p = {CLEAR, count, 0};
    p.seal();
    return p;
}

inline Packet ping(uint8_t pagerId) {
    Packet p = {PING, pagerId, 0};
    p.seal();
    return p;
}

inline Packet identify(uint8_t pagerId) {
    Packet p = {IDENTIFY, pagerId, 0};
    p.seal();
    return p;
}

inline Packet buzz(uint8_t halfSeconds) {
    Packet p = {BUZZ, halfSeconds, 0};
    p.seal();
    return p;
}

// ── Human-readable ───────────────────────────────────────────
inline const char *cmdName(uint8_t cmd) {
    switch (cmd) {
    case ALERT:    return "ALERT";
    case ACK:      return "ACK";
    case CLEAR:    return "CLEAR";
    case PING:     return "PING";
    case IDENTIFY: return "IDENTIFY";
    case BUZZ:     return "BUZZ";
    default:       return "?";
    }
}

} // namespace RaamsesProto
