# Raamses LoRa Protocol v1.1

Variable-length binary protocol for Raamses console <-> Pi gateway communication over Meshtastic private channel.

## Transport

- **Meshtastic port:** `PRIVATE_APP` (256)
- **Channel:** Secondary channel, name `"raamses"`, PSK `"raamses-mesh-key-2025"`
- **Encryption:** Handled by Meshtastic channel layer — no LRC/CRC in payload
- **Max payload:** 255 bytes (well within Meshtastic's ~237 byte limit)

## Wire Format

Every packet:

```
[0] cmd    uint8   Command (see below)
[1] len    uint8   Payload length (0-255)
[2..N]     bytes   Payload (len bytes)

Total: len + 2 bytes
```

Minimum valid packet: 2 bytes (cmd + len=0).

## Commands

### 0x01 ALERT — Agent needs help

| Offset | Size | Field |
|--------|------|-------|
| 0 | 1 | cmd = 0x01 |
| 1 | 1 | len = 3 |
| 2 | 1 | alert_count (rolling 0-255) |
| 3-4 | 2 | sequence (uint16, LE, monotonic per alert event) |

Sent by bridge when gateway poll detects agent needs help. **Sequence number** is monotonic per alert event — receivers reject ALERTs with seq <= last seen seq (prevents stale/duplicate processing). CLEAR references the same sequence.

### 0x02 ACK — Acknowledge receipt

| Offset | Size | Field |
|--------|------|-------|
| 0 | 1 | cmd = 0x02 |
| 1 | 1 | len = 1 |
| 2 | 1 | pager_id (0=bridge, 1-254=node) |

Sent by console to bridge after receiving ALERT.

### 0x03 CLEAR — Alert resolved

| Offset | Size | Field |
|--------|------|-------|
| 0 | 1 | cmd = 0x03 |
| 1 | 1 | len = 3 |
| 2 | 1 | alert_count |
| 3-4 | 2 | sequence (uint16, LE, matches the ALERT being cleared) |

Sent by bridge when gateway poll shows agent no longer needs help. **Same sequence as the ALERT** it resolves. Receivers ignore CLEAR with seq < last seen ALERT seq.

### 0x04 HEARTBEAT — Periodic keepalive

| Offset | Size | Field |
|--------|------|-------|
| 0 | 1 | cmd = 0x04 |
| 1 | 1 | len = 5 |
| 2-5 | 4 | node_id (uint32, LE, Meshtastic node number) |
| 6 | 1 | status byte |

Sent by consoles every 30 seconds. Status values:
- `0x00` OK
- `0x01` WiFi disconnected (bridge)
- `0x02` Gateway unreachable (bridge)
- `0x03` LoRa-only mode
- `0xFF` Error

### 0x05 REGISTER — Device registration

| Offset | Size | Field |
|--------|------|-------|
| 0 | 1 | cmd = 0x05 |
| 1 | 1 | len = 7 |
| 2-5 | 4 | node_id (uint32, LE) |
| 6 | 1 | device_type |
| 7-8 | 2 | firmware_version (uint16, LE: major=high, minor=low) |

Sent by console on boot (or WiFi fallback). Device types:
- `0x01` heltec_v3
- `0x02` heltec_v4
- `0x03` thinknode_m2

### 0x06 BUZZ — Test buzzer/LED

| Offset | Size | Field |
|--------|------|-------|
| 0 | 1 | cmd = 0x06 |
| 1 | 1 | len = 1 |
| 2 | 1 | duration_half_seconds |

Test command. Console flashes LED for `duration * 500ms`.

## Sequence Number Anti-Replay

ALERT and CLEAR carry a 2-byte monotonic sequence (uint16, little-endian). The bridge increments `alertSeq` for each new alert event.

Receivers:
- **ALERT:** if seq <= `lastAlertSeq`, ignore (stale/duplicate). Otherwise accept and update `lastAlertSeq`.
- **CLEAR:** if seq < `lastAlertSeq`, ignore (clearing an already-superseded alert). Otherwise accept.

This prevents:
- Re-broadcast storms (same ALERT received multiple times via mesh relay)
- Replaying old ALERTs after reboot
- CLEAR for an alert that was already replaced by a newer one

## Bridge Mesh→HTTP Relay

WiFi-connected bridges relay LoRa packets to the HTTP gateway so LoRa-only nodes appear in the device registry:

- **REGISTER** received on LoRa → `POST /register` with `"source":"lora_relay"`
- **HEARTBEAT** received on LoRa → `POST /heartbeat` with `"source":"lora_relay"`

This means the gateway sees ALL devices — WiFi bridges via direct HTTP, LoRa nodes via bridge relay.

## Flow Diagrams

### Bridge (WiFi + LoRa)

```
Boot → WiFi connect → HTTP POST /register (JSON) → HTTP poll /agents
  ↓ agent needs help
HTTP response → send ALERT(seq=N) over LoRa → LED flash
  ↓ cleared
HTTP response → send CLEAR(seq=N) over LoRa → dismiss

Also: relay incoming LoRa REGISTER/HEARTBEAT → HTTP gateway
```

### Node (LoRa only, no WiFi)

```
Boot → WiFi fails 3x → send REGISTER over LoRa
  → send HEARTBEAT every 30s
  → listen for ALERT(seq)/CLEAR(seq)
  → reject stale ALERTs by sequence number
```

### WiFi loss → LoRa fallback

```
GATEWAY_ACTIVE → WiFi drops → send REGISTER over LoRa
  → send HEARTBEAT every 30s
  → retry WiFi every 60s
```

## Gateway (Pi) Responsibilities

1. Join Raamses private channel (name `"raamses"`, PSK `"raamses-mesh-key-2025"`)
2. Listen on port 256 for Raamses packets
3. Parse variable-length format: `[cmd:1][len:1][payload:N]`
4. Handle REGISTER: add to device registry (SQLite), track `source` field
5. Handle HEARTBEAT: update last-seen timestamp
6. On agent-needs-help: increment seq, broadcast ALERT(count, seq) on Raamses channel
7. On agent-resolved: broadcast CLEAR(count, same_seq) on Raamses channel
8. HTTP `/agents` → return JSON with alert status per agent
9. HTTP `/register` → accept JSON (from WiFi bridges AND lora_relay)
10. HTTP `/heartbeat` → accept JSON (from WiFi bridges AND lora_relay)

## Security Notes

- Channel PSK is hardcoded (`RAAMSES_CHANNEL_KEY`). Same key on Pi gateway.
- Change the PSK before production deployment.
- Meshtastic provides AES-256-CCM encryption on the channel layer.
- Sequence numbers prevent replay within the channel.
- No authentication beyond channel membership.
