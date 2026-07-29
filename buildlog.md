mpiling .pio\build\thinknode-m2-raamses\hal\spi_hal.c.o
Compiling .pio\build\thinknode-m2-raamses\hal\spi_hal_iram.c.o
Compiling .pio\build\thinknode-m2-raamses\hal\spi_slave_hal.c.o
Compiling .pio\build\thinknode-m2-raamses\hal\spi_slave_hal_iram.c.o
Compiling .pio\build\thinknode-m2-raamses\hal\spi_slave_hd_hal.c.o
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp: In member function 'bool SPIClass::begin(int8_t, int8_t, int8_t, int8_t)':
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp:101:33: error: 'SCK' was not declared in this scope
  101 |     _sck = (_spi_num == FSPI) ? SCK : -1;
      |                                 ^~~
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp:102:34: error: 'MISO' was not declared in this scope
  102 |     _miso = (_spi_num == FSPI) ? MISO : -1;
Compiling .pio\build\thinknode-m2-raamses\hal\spi_flash_hal_gpspi.c.o
      |                                  ^~~~
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp:103:34: error: 'MOSI' was not declared in this scope
  103 |     _mosi = (_spi_num == FSPI) ? MOSI : -1;
      |                                  ^~~~
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp:104:32: error: 'SS' was not declared in this scope; did you mean 'ss'?
  104 |     _ss = (_spi_num == FSPI) ? SS : -1;
      |                                ^~
      |                                ss
Compiling .pio\build\thinknode-m2-raamses\hal\hmac_hal.c.o
Compiling .pio\build\thinknode-m2-raamses\hal\ds_hal.c.o
*** [.pio\build\thinknode-m2-raamses\SPI.cpp.o] Error 1
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.cpp: In member function 'bool TwoWire::initPins(int, int)':
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.cpp:73:18: error: 'SDA' was not declared in this scope
   73 |         sdaPin = SDA;  //use Default Pin
      |                  ^~~
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.cpp:94:18: error: 'SCL' was not declared in this scope
   94 |         sclPin = SCL;  // use Default pin
      |                  ^~~
*** [.pio\build\thinknode-m2-raamses\Wire.cpp.o] Error 1
In file included from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SD/src/SD.cpp:19:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SD/src/SD.h:31:21: error: 'SS' was not declared in this scope; did you mean 'FS'?
   31 |     uint8_t ssPin = ←[01;31m←[KSS←[m←[K, SPIClass &spi = SPI, uint32_t frequency = 4000000, const char *mountpoint = "/sd", uint8_t max_files = 5, bool format_if_empty = false
      |                     ^~
      |                     FS
*** [.pio\build\thinknode-m2-raamses\SD.cpp.o] Error 1
=========================================================================================== [FAILED] Took 49.79 seconds ===========================================================================================

Environment           Status    Duration
--------------------  --------  ------------
thinknode-m2-raamses  FAILED    00:00:49.788
====================================================================================== 1 failed, 0 succeeded in 00:00:49.788 ======================================================================================