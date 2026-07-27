# RaamsesMesh — Multi-Board Agent Alert Firmware

Meshtastic firmware fork that adds Raamses agent-alert display and haptic feedback
across multiple Meshtastic-compatible boards.

## Supported Boards

| Board | Build Target | Display | Alert Output | Status |
|-------|-------------|---------|-------------|--------|
| Heltec V3 | `heltec-v3-raamses` | SSD1306 OLED | GPIO 21 (ext. motor) | Tested |
| Heltec V4 | `heltec-v4-raamses` | SSD1306 OLED | GPIO 21 (ext. motor) | Drop-in |
| ThinkNode M2 | `thinknode-m2-raamses` | SH1106 OLED | IO1 (built-in buzzer) | Port |

## Building

```bash
pio run -e heltec-v3-raamses
pio run -e heltec-v4-raamses
pio run -e thinknode-m2-raamses
```

### Heltec V3 / V4

## What was changed

### New files

| File | Purpose |
|------|---------|
| `variants/esp32s3/heltec_v3_raamses/variant.h` | Board pinout + Raamses defines |
| `variants/esp32s3/heltec_v3_raamses/platformio.ini` | PlatformIO build target |
| `src/modules/esp32/RaamsesModule.h` | Module header |
| `src/modules/esp32/RaamsesModule.cpp` | Module implementation |
| `README-RAAMSES.md` | This file |

### Modified files

| File | Change |
|------|--------|
| `src/modules/Modules.cpp` | Added `#include` and instantiation of RaamsesModule |

### How it works

1. **Boot splash** — On startup the OLED shows "RAAMSES / agent alert console" for
   3 seconds, then the normal Meshtastic UI takes over.
2. **WiFi** — Connects to `seanrohde` / `piperbbs123` as a station.
3. **Gateway registration** — Registers with the Raamses gateway at
   `192.168.6.230:8765` using HTTP `POST /register`.
4. **Heartbeat** — Sends `POST /heartbeat` every 8 seconds.
5. **Polling** — `GET /agents` every 5 seconds, scanning the response for
   `"needs_help"`, `"needs help"`, `"AGENT_NEEDS_HELP"`, or `"status":"alert"`.
6. **Alert** — When an alert is detected, the screen shows "AGENT NEEDS HELP!"
   and the vibration motor pulses for 5 seconds (500ms on / 500ms off).
7. **Existing Meshtastic** — LoRa mesh, button menu navigation, and all other
   Meshtastic features continue to work normally.

## GPIO pin mapping (Heltec V3)

```
Pin  GPIO   Function
─────────────────────────────────────
 0    0     User button (Mesh UI)
 1    1     Battery ADC
 8    8     LoRa CS
 9    9     LoRa SCK
10   10     LoRa MOSI
11   11     LoRa MISO
12   12     LoRa RESET
13   13     LoRa DIO2 / BUSY
14   14     LoRa DIO1 / IRQ
21   21    >VIBRATION MOTOR<  ← NEW
37   37     ADC_CTRL
SDA  (41)   OLED I2C
SCL  (42)   OLED I2C
Vext        Power enable (OLED + LoRa boost)
```

## Wiring the vibration motor

```
        GPIO 21  ──[ 1KΩ ]──┐
                             │  B (base)
                        ┌────┴────┐
                        │   NPN   │  2N2222 / 2N3904 / S8050
                        │         │
                        └────┬────┘
                             │  E (emitter)
                             │
                            GND

        3.3V or 5V ──[ Motor ]──┐
                                 │  C (collector)
                                 │
               ┌─────────────────┘
               │  (flyback diode)
               ├──[ 1N4001 ]──┐  (cathode toward VCC)
               │               │
               └───────────────┘
                anode → GND side of motor
                cathode → VCC side of motor
```

- **GPIO 21** is available on the Heltec V3 pin headers (top row, 4th from left).
- Use an NPN transistor (2N2222, 2N3904, or S8050) — GPIO 21 drives the base
  via a 1KΩ resistor.
- **The 1N4001 flyback diode is mandatory** — without it the motor's back-EMF
  will kill the transistor and possibly the ESP32.
- If the motor draws >20mA from GPIO, you MUST use the transistor circuit above.
  Never connect a motor directly to a GPIO pin.

### Power notes

- A **coin/pancake vibration motor** (10mm, 3V) works well off the 3.3V rail.
- If using a larger motor, power it from the Vext or USB 5V rail via a MOSFET
  instead.  An AO3400 N-channel MOSFET can switch 5V from GPIO 21 without a
  transistor.

## Building

```bash
# Prerequisites: PlatformIO
pip install platformio

# Build the Raamses variant
cd firmware
pio run -e heltec-v3-raamses

# Flash to device
pio run -e heltec-v3-raamses -t upload --upload-port /dev/ttyUSB0
```

## Gateway API format expected

The Raamses gateway must return one of these patterns in `GET /agents`:

```json
{"agents": [{..., "status": "alert", "needs_help": true}]}
// OR
{"agents": [{..., "needs_help": true}]}
// OR
"AGENT_NEEDS_HELP"
```

**If your gateway doesn't currently expose a `needs_help` field**, you'll need
to add one.  The simplest approach: add `"needs_help": true` to any agent whose
status transitions to "alert" in the `/agents` response.

## Future: Meshtastic alert relay

The module is structured so that once "agent needs help" is detected, the alert
can be broadcast over the Meshtastic mesh to partner devices (pagers, other
nodes).  The `ALERT` state is already wired — just add mesh packet transmission
in `runOnce()` under that case.

## ThinkNode M2 specifics

The M2 has a **built-in buzzer** on IO1 (shared with the power LED). No external
vibration motor needed — the buzzer pulses audibly when an alert fires.

### M2 GPIO reference

```
Pin   GPIO   Function
────────────────────────────────
SCL   15     OLED I2C clock
SDA   16     OLED I2C data
46    46     Display power control
47    47     FUNCTION button (UI navigation)
4      4     POWER button
0      0     BOOT button
1      1     Buzzer + Power LED (Raamses alert)
10    10     LoRa CS
12    12     LoRa SCK
11    11     LoRa MOSI
13    13     LoRa MISO
21    21     LoRa RESET
14    14     LoRa BUSY
3      3     LoRa DIO1
```

**Note:** If the buzzer doesn't respond on IO1, check the board schematic.
The buzzer may be on a different pin (possibly IO6). The `VIBRATION_MOTOR_PIN`
in variant.h is easy to change.

## Pitfalls

- **Registration race**: the gateway has a ~500ms race between registration and
  indexing. The module waits an extra 600ms before the first poll to avoid a
  false "not registered" error.
- **WiFi conflict**: if Meshtastic's WiFi web server (HTTPS/WiFi config) is
  enabled, it may conflict with the STA connection. Use AP+STA mode or disable
  the web server if both are needed simultaneously.
- **Screen conflict**: the alert screen paints directly to the OLED. The normal
  Meshtastic UI will overwrite it within one frame cycle (~200ms). For a
  persistent alert, consider using `screen->startAlert()` instead.
