// pins_arduino.h for Heltec V4 Raamses
// Uses board_level = extra to override the framework's missing variant
// Pin mappings come from heltec_v4 variant.h

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>
#include <variant.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

// Serial
static const uint8_t TX = UART_TX;
static const uint8_t RX = UART_RX;

// Default SPI will be mapped to Radio
static const uint8_t SS = LORA_CS;
static const uint8_t SCK = LORA_SCK;
static const uint8_t MOSI = LORA_MOSI;
static const uint8_t MISO = LORA_MISO;

// Default I2C
static const uint8_t SCL = I2C_SCL;
static const uint8_t SDA = I2C_SDA;

#endif /* Pins_Arduino_h */
