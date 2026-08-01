/*
 * Heltec WiFi LoRa 32 V3 — Raamses variant
 *
 * TODO (Sean): fill in pin definitions for your specific build.
 * Known Heltec V3 pins from the skill reference:
 *   GPIO 0   — User button
 *   GPIO 1   — Battery ADC
 *   GPIO 8-11 — LoRa SPI
 *   GPIO 12-14 — LoRa control
 *   GPIO 21  — Free (vibration motor on Raamses builds)
 *   GPIO 37  — ADC_CTRL
 *   GPIO 41/42 — OLED I2C
 */

#pragma once

#define HELTEC_V3
#define HAS_RAAMSES
#define HAS_SCREEN
#define HAS_SX1262

/* ── TODO: verify / adjust these ─────────────────────────── */

// LoRa radio (SX1262)
#define USE_SX1262
#define SX126X_CS     (8)
#define SX126X_DIO1   (14)
#define SX126X_BUSY   (13)
#define SX126X_RESET  (12)
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8

// OLED display (I2C)
#define I2C_SDA       (41)
#define I2C_SCL       (42)
#define OLED_ADDR     0x3C

// User button
#define BUTTON_PIN    (0)
#define PIN_BUTTON    (0)
#define BUTTON_NEED_PULLUP

// Vibration motor (NPN transistor driven)
#define VIBRATION_MOTOR_PIN (21)

// Battery ADC
#define BATTERY_PIN   (1)
#define ADC_MULTIPLIER 2.0

// LED
#define LED_PIN       (35)
#define LED_STATE_ON  1
