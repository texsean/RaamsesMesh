// pins_arduino.h — ThinkNode M2 Raamses (ESP32-S3)
// SPI/I2C pin definitions. #ifndef guards allow -D build flags to override.

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>
#include <variant.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

// Serial
#ifndef TX
static const uint8_t TX = 43;
#endif
#ifndef RX
static const uint8_t RX = 44;
#endif

// SPI (FSPI/VSPI)
#ifndef SS
static const uint8_t SS   = 10;
#endif
#ifndef SCK
static const uint8_t SCK  = 12;
#endif
#ifndef MOSI
static const uint8_t MOSI = 11;
#endif
#ifndef MISO
static const uint8_t MISO = 13;
#endif

// I2C
#ifndef SDA
static const uint8_t SDA = 16;
#endif
#ifndef SCL
static const uint8_t SCL = 15;
#endif

#endif /* Pins_Arduino_h */
