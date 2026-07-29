// pins_arduino.h — ThinkNode M2 Raamses (ESP32-S3)
// Provides SPI pin definitions required by the Espressif framework's SPI.cpp
// board_level = extra makes PlatformIO use this instead of the framework's version

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>
#include <variant.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

// Serial
static const uint8_t TX = 43;
static const uint8_t RX = 44;

// SPI (VSPI / FSPI on ESP32-S3)
static const uint8_t SS   = 10;
static const uint8_t SCK  = 12;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 13;

// I2C
static const uint8_t SCL = 5;
static const uint8_t SDA = 4;

#endif /* Pins_Arduino_h */
