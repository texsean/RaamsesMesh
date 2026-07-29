// pins_arduino.h — ThinkNode M2 Raamses (ESP32-S3)
// All pin definitions use #ifndef guards so -D flags from CPPDEFINES
// take precedence without conflicting with static const definitions.

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

#ifndef SS
static const uint8_t SS = 10;
#endif
#ifndef SCK
static const uint8_t SCK = 12;
#endif
#ifndef MOSI
static const uint8_t MOSI = 11;
#endif
#ifndef MISO
static const uint8_t MISO = 13;
#endif

#ifndef SDA
static const uint8_t SDA = 16;
#endif
#ifndef SCL
static const uint8_t SCL = 15;
#endif

#ifndef TX
static const uint8_t TX = 43;
#endif
#ifndef RX
static const uint8_t RX = 44;
#endif

#endif /* Pins_Arduino_h */
