#define LED_POWER LED

#define USE_SSD1306 // Heltec V4 has a SSD1306 display (same as V3)

#define RESET_OLED RST_OLED
#define I2C_SDA SDA_OLED
#define I2C_SCL SCL_OLED

#define I2C_SDA1 SDA
#define I2C_SCL1 SCL

#define VEXT_ENABLE Vext // active low, powers oled + lora boost
#define BUTTON_PIN 0

#define ADC_CTRL 37
#define ADC_CTRL_ENABLED LOW
#define BATTERY_PIN 1
#define ADC_CHANNEL ADC_CHANNEL_0
#define ADC_ATTENUATION ADC_ATTEN_DB_2_5
#define ADC_MULTIPLIER 4.9 * 1.045

#define USE_SX1262

#define LORA_DIO0 -1
#define LORA_RESET 12
#define LORA_DIO1 14
#define LORA_DIO2 13
#define LORA_DIO3

#define LORA_SCK 9
#define LORA_MISO 11
#define LORA_MOSI 10
#define LORA_CS 8

#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET

#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8

#define HAS_32768HZ 1

// ───── Raamses Integration ─────
// Vibration motor on GPIO 21 (free header pin, same location as V3).
// V4 pins are drop-in compatible with V3 per Heltec documentation.
#define VIBRATION_MOTOR_PIN 21

// Built-in LED on GPIO 35 (active low on Heltec V4)
#define LED_PIN 35
#define LED_STATE_ON 0

#define RAAMSES_WIFI_SSID "seanrohde"
#define RAAMSES_WIFI_PASS "piperbbs123"

#define RAAMSES_GATEWAY_HOST "192.168.6.230"
#define RAAMSES_GATEWAY_PORT 8765

#define RAAMSES_DEVICE_TYPE "heltec_v4"

#define HAS_RAAMSES 1
