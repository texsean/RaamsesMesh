// ThinkNode M2 — Elecrow Meshtastic Transceiver
// ESP32-S3, SX1262 LoRa, SH1106 1.3" OLED, built-in buzzer
// Pinout from Elecrow wiki: https://www.elecrow.com/wiki/ThinkNode-M2

#define LED_POWER 1
#define LED_PIN 1

// Display: 1.3" OLED SH1106, I2C
#define USE_SH1106
#define HAS_SCREEN 1
#define I2C_SDA 16
#define I2C_SCL 15

// Display power control
#define VTFT_CTRL 46

// Buttons
#define BUTTON_PIN 47  // FUNCTION button (single-click: next frame, double: ping, triple: SOS)

// LoRa SX1262
#define USE_SX1262

#define LORA_SCK 12
#define LORA_MISO 13
#define LORA_MOSI 11
#define LORA_CS 10

#define LORA_DIO0 -1
#define LORA_RESET 21
#define LORA_DIO1 3   // SX1262 IRQ
#define LORA_DIO2 -1  // RF switch control, handled by SX1262 macro
#define LORA_DIO3 -1  // TCXO power

#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY 14
#define SX126X_RESET LORA_RESET

#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8

// Battery ADC (not confirmed from wiki; using IO5 as likely candidate)
// The M2 has internal battery management — ADC pin TBD on actual board
// #define BATTERY_PIN 5
// #define ADC_CHANNEL ADC_CHANNEL_0
// #define ADC_MULTIPLIER 2.0

// ───── Raamses Integration ─────
// Built-in buzzer on IO1 (shared with LED indicator)
#define VIBRATION_MOTOR_PIN 1   // Use the built-in buzzer instead of external motor

#define RAAMSES_WIFI_SSID "seanrohde"
#define RAAMSES_WIFI_PASS "piperbbs123"

#define RAAMSES_GATEWAY_HOST "192.168.6.230"
#define RAAMSES_GATEWAY_PORT 8765

#define RAAMSES_DEVICE_TYPE "thinknode_m2"

#define HAS_RAAMSES 1
