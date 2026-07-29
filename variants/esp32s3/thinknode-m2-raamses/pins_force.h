// Force-included SPI/I2C pin defines for ThinkNode M2 Raamses
// This header is injected into EVERY compilation unit via -include,
// so framework SPI.cpp and Wire.cpp see these defines.

// SPI (FSPI / VSPI)
#define SS   10
#define SCK  12
#define MOSI 11
#define MISO 13

// I2C
#define SDA  16
#define SCL  15
