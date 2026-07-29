/*
 * ThinkNode M2 — Raamses variant
 *
 * ESP32-S3 + SX1262 LoRa module.
 *
 * TODO (Sean): fill in correct pin definitions for the ThinkNode M2.
 * These are placeholder defaults for an ESP32-S3 dev board + external
 * SX1262 module.
 */

#pragma once

#ifndef THINKNODE_M2
#define THINKNODE_M2
#endif
#ifndef HAS_RAAMSES
#define HAS_RAAMSES
#endif
#ifndef HAS_SCREEN
#define HAS_SCREEN
#endif
#ifndef HAS_SX1262
#define HAS_SX1262
#endif

/* ── TODO: verify / adjust these ─────────────────────────── */

// SPI pins (required by framework spi.cpp / wire.cpp)
#define MOSI  11
#define MISO  13
#define SCK   12
#define SS    10

// LoRa radio (SX1262)
#define USE_SX1262
#define SX126X_CS     (10)
#define SX126X_DIO1   (9)
#define SX126X_BUSY   (8)
#define SX126X_RESET  (7)
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8

// OLED display (I2C — TODO: confirm pins)
#define I2C_SDA       (4)
#define I2C_SCL       (5)
#define OLED_ADDR     0x3C

// Vibration motor (set to -1 if no motor on this board)
#define VIBRATION_MOTOR_PIN (-1)

// LED (built-in on many dev boards)
#define LED_PIN       (48)
#define LED_STATE_ON  1
