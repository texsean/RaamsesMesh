# Raamses LoRa Protocol v1.0

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
| 1 | 1 | len = 1 |
| 2 | 1 | alert_count (rolling 0-255) |

Sent by bridge when gateway poll detects agent needs help. Received by all consoles — triggers display + LED flash.

### 0x02 ACK — Acknowledge receipt

| Offset | Size | Field |
|--------|------|-------|
| 0 | 1 | cmd = 0x02 |
| 1 | 1 | len = 1 |
| 2 | 1 | pager_id (0=bridge, 1-254=node) |

Sent by console to bridge after receiving ALERT. Bridge can track which pagers acknowledged.

### 0x03 CLEAR — Alert resolved

| Offset | Size | Field |
|--------|------|-------|
| 0 | 1 | cmd = 0x03 |
| 1 | 1 | len = 1 |
| 2 | 1 | alert_count |

Sent by bridge when gateway poll shows agent no longer needs help. All consoles dismiss alert.

### 0x04 HEARTBEAT — Periodic keepalive

| Offset | Size | Field |
|--------|------|-------|
| 0 | 1 | cmd = 0x04 |
| 1 | 1 | len = 5 |
| 2-5 | 4 | node_id (uint32, little-endian, Meshtastic node number) |
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

## Flow Diagrams

### Bridge (WiFi + LoRa)

```
Boot → WiFi connect → HTTP POST /register (JSON) → HTTP poll /agents
  ↓ agent needs help
HTTP response → send ALERT over LoRa → buzz + LED
  ↓ cleared
HTTP response → send CLEAR over LoRa → dismiss
```

### Node (LoRa only, no WiFi)

```
Boot → WiFi fails 3x → send REGISTER over LoRa
  → send HEARTBEAT every 30s
  → listen for ALERT/CLEAR
```

### WiFi loss → LoRa fallback

```
GATEWAY_ACTIVE → WiFi drops → send REGISTER over LoRa
  → send HEARTBEAT every 30s
  → retry WiFi every 60s
```

## Gateway (Pi) Responsibilities

1. Listen for REGISTER on Raamses channel → add to device registry
2. Listen for HEARTBEAT → update last-seen timestamp
3. On agent-needs-help event → broadcast ALERT on Raamses channel
4. On agent-resolved event → broadcast CLEAR on Raamses channel
5. HTTP endpoint `/agents` → return JSON with alert status for bridges
6. HTTP endpoint `/register` → accept JSON registration from bridges
7. HTTP endpoint `/heartbeat` → accept JSON heartbeat from bridges

## Security Notes

- Channel PSK is hardcoded in firmware (`RAAMSES_CHANNEL_KEY`). Same key on Pi gateway.
- Change the PSK before production deployment.
- Meshtastic provides AES-256-CCM encryption on the channel layer.
- No authentication beyond channel membership — any device with the PSK can send commands.
