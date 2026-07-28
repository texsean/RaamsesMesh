# RAAMSES for Meshtastic

> **Long-range AI & DevOps notifications over LoRa.**
>
> Receive RAAMSES alerts on Meshtastic-compatible devices while preserving the full Meshtastic experience.

---

## Why?

Modern AI agents don't stop working when you leave your desk.

Whether you're running Claude Code, Hermes, Grok, local Qwen models, CI/CD pipelines, Kubernetes clusters, or traditional DevOps infrastructure, important events can happen at any time.

RAAMSES allows those events to be delivered to Meshtastic devices over LoRa, creating an ultra-low-power, long-range notification console.

Imagine receiving:

- CI Build Failed
- VPN Down
- Agent Waiting for Approval
- Production Deployment Complete
- Server Offline
- Security Alert
- Backup Failed

...even when you're miles away from Wi-Fi.

---

# What is RAAMSES?

RAAMSES (Remote AI Agent Monitoring & Server Escalation System) is an AI Operations platform that monitors AI agents, servers, infrastructure, and automation workflows.

The Meshtastic integration turns compatible LoRa devices into long-range RAAMSES consoles.

The gateway handles all AI communication.

Your Meshtastic device simply becomes another RAAMSES console.

---

# Design Goals

- Preserve full Meshtastic functionality
- Add optional RAAMSES support
- Minimize code changes
- Keep board definitions clean
- Keep changes upstream-friendly
- Make RAAMSES entirely optional
- Keep power consumption low
- Respect existing Meshtastic design principles

---

# Non-Goals

This project does **not** attempt to:

- Replace the Meshtastic UI
- Change Meshtastic networking
- Fork or modify the LoRa protocol
- Break compatibility with existing devices
- Add cloud dependencies
- Force users to use RAAMSES

If RAAMSES is disabled, the firmware behaves exactly like standard Meshtastic.

---

# Philosophy

RAAMSES is designed as an optional extension—not a replacement.

Think of it as another application that happens to speak the RAAMSES protocol.

The goal is for users to continue enjoying everything Meshtastic already does while optionally receiving intelligent operational alerts.

---

# Example Alerts

```
CI BUILD FAILED

BuildServer-01

22:48
```

```
VPN DOWN

Office-West

22:47
```

```
AGENT WAITING

Deploy v1.4?

YES   NO
```

```
PRODUCTION

Deployment Complete

Success
```

---

# Architecture

```
AI Agents
CI/CD
Servers
Containers
Automation
        │
        │
 RAAMSES Gateway
        │
 XML / HTTPS
        │
 RangePi Bridge
        │
 LoRa / Meshtastic
        │
 RAAMSES Console
```

The Meshtastic device is simply another RAAMSES console.

---

# Current Features

- Optional RAAMSES module
- LoRa alert delivery
- Gateway registration
- Device identification
- Alert acknowledgements
- Vibration notification support
- Tiny OLED UI
- Low-power operation
- 3-byte compact binary LoRa protocol
- Bridge + Node dual-mode operation
- Multi-board support (Heltec V3, V4, ThinkNode M2)

---

# Planned Features

- Alert history
- Approval prompts
- Multiple alert priorities
- Silent mode
- Device groups
- OTA configuration
- Secure pairing
- Multi-gateway failover

---

# Supported Boards

| Board | Build Target | Display | Alert Output |
|-------|-------------|---------|-------------|
| Heltec V3 | `heltec-v3-raamses` | SSD1306 OLED | GPIO 21 (ext. motor) |
| Heltec V4 | `heltec-v4-raamses` | SSD1306 OLED | GPIO 21 (ext. motor) |
| ThinkNode M2 | `thinknode-m2-raamses` | SH1106 OLED | IO1 (built-in buzzer) |

## Quick Build

```bash
git clone https://github.com/texsean/RaamsesMesh.git
cd RaamsesMesh
pio run -e heltec-v3-raamses      # Heltec V3
pio run -e heltec-v4-raamses      # Heltec V4
pio run -e thinknode-m2-raamses   # ThinkNode M2
```

For detailed build instructions, wiring diagrams, and the LoRa protocol spec, see [TECH.md](TECH.md).

---

# Contributing

Contributions are welcome.

Please help us:

- Keep changes small
- Preserve upstream compatibility
- Follow existing Meshtastic coding conventions
- Avoid unnecessary architectural changes
- Keep RAAMSES optional

If a feature benefits Meshtastic users in general, we'd love to see it accepted upstream.

---

# Powered by RAAMSES

One Server.

Any Console.

Anywhere.

Android • Desktop • ESP32 • M5Stack • E-Paper • Meshtastic • Future Devices

---

**This project is not affiliated with the Meshtastic project.**

It is an optional integration intended to work alongside the excellent Meshtastic ecosystem while respecting its architecture and community.
