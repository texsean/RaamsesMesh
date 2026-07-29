PS C:\GitHub\RaamsesMesh\RaamsesMesh> pio run -e thinknode-m2-raamses -t upload --upload-port COM25
Processing thinknode-m2-raamses (board: ESP32-S3-WROOM-1-N4; platform:
https://github.com/meshtastic/pioarduino-platform-espressif32/archive/refs/heads/55.03.39.zip; framework: arduino)
--------------------------------------------------------------------------------------------------------------------
Verbose mode can be enabled via `-v, --verbose` option
PROGNAME: firmware-thinknode-m2-raamses-2.8.0.b48ced1
ESP32_FS_IMAGE_NAME: littlefs-thinknode-m2-raamses-2.8.0.b48ced1
CONFIGURATION: https://docs.platformio.org/page/boards/espressif32/ESP32-S3-WROOM-1-N4.html
PLATFORM: Espressif 32 (55.3.39) > ESP32-S3-WROOM-1-N4 (4 MB Flash, No PSRAM)
HARDWARE: ESP32S3 240MHz, 512KB RAM, 4MB Flash
DEBUG: Current (esp-builtin) On-board (esp-builtin) External (cmsis-dap, esp-bridge, esp-prog, esp-prog-2, iot-bus-jtag, jlink, minimodule, olimex-arm-usb-ocd, olimex-arm-usb-ocd-h, olimex-arm-usb-tiny-h, olimex-jtag-tiny, tumpa)
PACKAGES:
 - contrib-piohome @ 3.4.4
 - framework-arduinoespressif32 @ 3.3.9
 - framework-arduinoespressif32-libs @ 5.5.4+sha.735507283d
 - framework-espidf @ 3.50504.0 (5.5.4)
 - tool-cmake @ 4.0.3
 - tool-cppcheck @ 2.20.1
 - tool-esp-rom-elfs @ 2024.10.11
 - tool-esptoolpy @ 5.3.0
 - tool-mklittlefs @ 1.203.210628 (2.3)
 - tool-ninja @ 1.13.1
 - tool-scons @ 4.40801.0 (4.8.1)
 - tool-xtensa-esp-elf-gdb @ 17.1.0+20260402
 - toolchain-xtensa-esp-elf @ 14.2.0+20260121
[ComponentManager] BT/BLE protection enabled
[ComponentManager] Protected BT library: bt
[ComponentManager] Protected BT library: nimble-arduino
[ComponentManager] Processed 15 ignored libraries
[ComponentManager] Session completed with 4 changes
*** Added LTO flags for Arduino compile ***
LDF: Library Dependency Finder -> https://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
[nanopb] Installing Protocol Buffers dependencies
C:\Users\seanr\.platformio\penv\Scripts\python.exe: No module named pip
[nanopb] Installing gRPC dependencies
C:\Users\seanr\.platformio\penv\Scripts\python.exe: No module named pip
[nanopb] No generation needed.
Found 98 compatible libraries
Scanning dependencies...
Dependency Graph
|-- ESP8266 and ESP32 OLED driver for SSD1306 displays @ 4.4.1
|-- OneButton @ 2.6.1
|-- arduino-fsm @ 2.2.0
|-- TinyGPSPlus @ 1.0.3
|-- ArduinoThread @ 0.0.0+20260729094026
|-- Nanopb @ 0.4.9+1
|-- ErriezCRC32 @ 1.0.1
|-- NonBlockingRTTTL @ 1.4.0
|-- TBPubSubClient @ 2.12.1
|-- NTPClient @ 3.2.1
|-- Adafruit BusIO @ 1.17.4
|-- Adafruit Unified Sensor @ 1.1.15
|-- Adafruit GFX Library @ 1.12.6
|-- Adafruit NeoPixel @ 1.15.5
|-- Adafruit SSD1306 @ 2.5.17
|-- Adafruit BMP280 Library @ 3.0.0
|-- Adafruit BMP085 Library @ 1.2.4
|-- Adafruit BME280 Library @ 2.3.0
|-- Adafruit DPS310 @ 1.1.6
|-- Adafruit SH110X @ 2.1.14
|-- Adafruit MCP9808 Library @ 2.0.2
|-- Adafruit INA260 Library @ 1.5.3
|-- Adafruit INA219 @ 1.2.3
|-- Adafruit MPU6050 @ 2.2.9
|-- Adafruit LIS3DH @ 1.3.0
|-- Adafruit AHTX0 @ 2.0.6
|-- Adafruit LSM6DS @ 4.7.4
|-- Adafruit TSL2591 Library @ 1.4.5
|-- EmotiBit MLX90632 @ 1.0.8
|-- Adafruit MLX90614 Library @ 2.1.6
|-- INA3221 @ 0.4.2
|-- QMC5883LCompass @ 1.2.3
|-- DFRobot_RTU @ 1.0.6
|-- DFRobot_RainfallSensor @ 1.0.0
|-- INA226 @ 0.6.6
|-- SparkFun MAX3010x Pulse and Proximity Sensor Library @ 1.1.2
|-- SparkFun 9DoF IMU Breakout - ICM 20948 - Arduino Library @ 1.3.2
|-- ICM42670P @ 1.0.8
|-- Adafruit LTR390 Library @ 1.1.2
|-- Adafruit PCT2075 @ 1.0.1
|-- DFRobot_BMM150 @ 1.0.0
|-- SparkFun MMC5983MA Magnetometer Arduino Library @ 1.1.5
|-- Adafruit TSL2561 @ 1.1.3
|-- BH1750_WE @ 1.1.10
|-- Fusion @ 1.2.12
|-- Sensirion Core @ 0.7.3
|-- Sensirion I2C SCD4x @ 1.1.0
|-- Sensirion I2C SFA3x @ 1.0.0
|-- Sensirion I2C SCD30 @ 1.1.1
|-- arduino-sht @ 1.2.6
|-- Adafruit SPA06_003 @ 1.0.2
|-- Adafruit BMP3XX Library @ 2.1.6
|-- Adafruit MAX1704X @ 1.0.3
|-- Adafruit LPS2X @ 2.0.6
|-- Adafruit VEML7700 Library @ 2.1.6
|-- SparkFun Qwiic Scale NAU7802 Arduino Library @ 1.0.6
|-- ClosedCube OPT3001 @ 1.1.2
|-- DFRobot_LarkWeatherStation @ 1.0.0
|-- bsec2 @ 1.10.2610
|-- BME68x Sensor library @ 1.3.40408
|-- RadioLib @ 7.7.1
|-- esp32_https_server @ 1.0.0
|-- libpax @ 1.1.0
|-- XPowersLib @ 0.3.3
|-- Crypto @ 0.0.0+20260729094041
|-- ESP32 Codec2 @ 1.0.1
|-- SD @ 3.3.9
|-- SPI @ 3.3.9
|-- Ethernet @ 3.3.9
|-- WiFi @ 3.3.9
|-- Wire @ 3.3.9
|-- Preferences @ 3.3.9
|-- WebServer @ 3.3.9
|-- ESPmDNS @ 3.3.9
|-- HTTPClient @ 3.3.9
|-- BLE @ 3.3.9
|-- LittleFS @ 3.3.9
|-- NetworkClientSecure @ 3.3.9
|-- ESP32 Async UDP @ 3.3.9
Building in release mode
Using meshtastic platformio-custom.py, firmware version 2.8.0.b48ced1 on thinknode-m2-raamses
Using flags:
-DAPP_VERSION=2.8.0.b48ced1
-DAPP_VERSION_SHORT=2.8.0
-DAPP_ENV=thinknode-m2-raamses
-DAPP_REPO=git@github.com:texsean/RaamsesMesh
-DBUILD_EPOCH=1785301200
-DUSERPREFS_RINGTONE_RTTTL=\"24:d=32,o=5,b=565:f6,p,f6,4p,p,f6,p,f6,2p,p,b6,p,b6,p,b6,p,b6,p,b,p,b,p,b,p,b,p,b,p,b,p,b,p,b,1p.,2p.,p\"
-DUSERPREFS_TZ_STRING=\"tzplaceholder                                         \"
Compiling .pio\build\thinknode-m2-raamses\lib0ce\Wire\Wire.cpp.o
Compiling .pio\build\thinknode-m2-raamses\lib935\SPI\SPI.cpp.o
Compiling .pio\build\thinknode-m2-raamses\lib8e4\ESP8266 and ESP32 OLED driver for SSD1306 displays\OLEDDisplay.cpp.o
Compiling .pio\build\thinknode-m2-raamses\lib8e4\ESP8266 and ESP32 OLED driver for SSD1306 displays\OLEDDisplayFonts.cpp.o
Compiling .pio\build\thinknode-m2-raamses\lib8e4\ESP8266 and ESP32 OLED driver for SSD1306 displays\OLEDDisplayUi.cpp.o
Compiling .pio\build\thinknode-m2-raamses\libd44\OneButton\OneButton.cpp.o
Compiling .pio\build\thinknode-m2-raamses\libd44\OneButton\OneButtonTiny.cpp.o
Compiling .pio\build\thinknode-m2-raamses\lib955\arduino-fsm\Fsm.cpp.o
Compiling .pio\build\thinknode-m2-raamses\lib2e9\TinyGPSPlus\TinyGPS++.cpp.o
Compiling .pio\build\thinknode-m2-raamses\libf7b\ArduinoThread\Thread.cpp.o
Compiling .pio\build\thinknode-m2-raamses\libf7b\ArduinoThread\ThreadController.cpp.o
Compiling .pio\build\thinknode-m2-raamses\lib45f\Nanopb\pb_common.c.o
Compiling .pio\build\thinknode-m2-raamses\lib45f\Nanopb\pb_decode.c.o
Compiling .pio\build\thinknode-m2-raamses\lib45f\Nanopb\pb_encode.c.o
Compiling .pio\build\thinknode-m2-raamses\libca1\ErriezCRC32\ErriezCRC32.c.o
Compiling .pio\build\thinknode-m2-raamses\liba49\NonBlockingRTTTL\NonBlockingRtttl.cpp.o
Compiling .pio\build\thinknode-m2-raamses\lib776\TBPubSubClient\PubSubClient.cpp.o
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.cpp: In member function 'bool TwoWire::initPins(int, int)':
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.cpp:73:18: error: 'SDA' was not declared in this scope
   73 |         sdaPin = SDA;  //use Default Pin
      |                  ^~~
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.cpp:94:18: error: 'SCL' was not declared in this scope
   94 |         sclPin = SCL;  // use Default pin
      |                  ^~~
Compiling .pio\build\thinknode-m2-raamses\lib31a\NTPClient\NTPClient.cpp.o
*** [.pio\build\thinknode-m2-raamses\lib0ce\Wire\Wire.cpp.o] Error 1
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp: In member function 'bool SPIClass::begin(int8_t, int8_t, int8_t, int8_t)':
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp:101:33: error: 'SCK' was not declared in this scope
  101 |     _sck = (_spi_num == FSPI) ? SCK : -1;
      |                                 ^~~
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp:102:34: error: 'MISO' was not declared in this scope
  102 |     _miso = (_spi_num == FSPI) ? MISO : -1;
      |                                  ^~~~
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp:103:34: error: 'MOSI' was not declared in this scope
  103 |     _mosi = (_spi_num == FSPI) ? MOSI : -1;
      |                                  ^~~~
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp:104:32: error: 'SS' was not declared in this scope; did you mean 'ss'?
  104 |     _ss = (_spi_num == FSPI) ? SS : -1;
      |                                ^~
      |                                ss
*** [.pio\build\thinknode-m2-raamses\lib935\SPI\SPI.cpp.o] Error 1
=========================================== [FAILED] Took 46.65 seconds ===========================================

Environment           Status    Duration
--------------------  --------  ------------
thinknode-m2-raamses  FAILED    00:00:46.650
====================================== 1 failed, 0 succeeded in 00:00:46.650 ======================================