// pins_arduino.h — ThinkNode M2 Raamses (ESP32-S3)
// All pin definitions use #ifndef guards so -D flags from CPPDEFINES
// (force_arduino.py) take precedence without conflicting with static const
// definitions.

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>
#include <variant.h>  // chain → Arduino.h → framework core types

#define USB_VID 0x303a
#define USB_PID 0x1001

// SPI (default to radio pins if CPPDEFINES haven't set them via -D)
#ifndef SS
static const uint8_t SS = LORA_CS;
#endif
#ifndef SCK
static const uint8_t SCK = LORA_SCK;
#endif
#ifndef MOSI
static const uint8_t MOSI = LORA_MOSI;
#endif
#ifndef MISO
static const uint8_t MISO = LORA_MISO;
#endif

// I2C
#ifndef SCL
static const uint8_t SCL = I2C_SCL;
#endif
#ifndef SDA
static const uint8_t SDA = I2C_SDA;
#endif

// UART (generic ESP32-S3 default — UART_TX/UART_RX are not pre-defined
// macros on this board, so use raw pin numbers)
#ifndef TX
static const uint8_t TX = 43;
#endif
#ifndef RX
static const uint8_t RX = 44;
#endif

#endif /* Pins_Arduino_h */
