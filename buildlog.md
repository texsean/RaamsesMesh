Building in release mode
Using meshtastic platformio-custom.py, firmware version 2.8.0.a91b39b on heltec-v4-raamses
Using flags:
-DAPP_VERSION=2.8.0.a91b39b
-DAPP_VERSION_SHORT=2.8.0
-DAPP_ENV=heltec-v4-raamses
-DAPP_REPO=git@github.com:texsean/RaamsesMesh
-DBUILD_EPOCH=1785474000
-DUSERPREFS_RINGTONE_RTTTL=\"24:d=32,o=5,b=565:f6,p,f6,4p,p,f6,p,f6,2p,p,b6,p,b6,p,b6,p,b6,p,b,p,b,p,b,p,b,p,b,p,b,p,b,p,b,1p.,2p.,p\"
-DUSERPREFS_TZ_STRING=\"tzplaceholder                                         \"
Compiling .pio\build\heltec-v4-raamses\lib0ce\Wire\Wire.cpp.o
Compiling .pio\build\heltec-v4-raamses\lib935\SPI\SPI.cpp.o
Compiling .pio\build\heltec-v4-raamses\libee4\ESP8266 and ESP32 OLED driver for SSD1306 displays\OLEDDisplay.cpp.o
Compiling .pio\build\heltec-v4-raamses\libee4\ESP8266 and ESP32 OLED driver for SSD1306 displays\OLEDDisplayFonts.cpp.o
Compiling .pio\build\heltec-v4-raamses\libee4\ESP8266 and ESP32 OLED driver for SSD1306 displays\OLEDDisplayUi.cpp.o
In file included from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.cpp:22:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src/SPI.h:28:10: fatal error: pins_arduino.h: No such file or directory

**********************************************************************
* Looking for pins_arduino.h dependency? Check our library registry!
*
* CLI  > platformio lib search "header:pins_arduino.h"
* Web  > https://registry.platformio.org/search?q=header:pins_arduino.h
*
**********************************************************************

   28 | #include "pins_arduino.h"
      |          ^~~~~~~~~~~~~~~~
compilation terminated.
Compiling .pio\build\heltec-v4-raamses\libf35\OneButton\OneButton.cpp.o
*** [.pio\build\heltec-v4-raamses\lib935\SPI\SPI.cpp.o] Error 1
In file included from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/cores/esp32/esp32-hal.h:115,
                 from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.h:33,
                 from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.cpp:38:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/cores/esp32/esp32-hal-gpio.h:27:10: fatal error: pins_arduino.h: No such file or directory

**********************************************************************
* Looking for pins_arduino.h dependency? Check our library registry!
*
* CLI  > platformio lib search "header:pins_arduino.h"
* Web  > https://registry.platformio.org/search?q=header:pins_arduino.h
*
**********************************************************************

   27 | #include "pins_arduino.h"
      |          ^~~~~~~~~~~~~~~~
compilation terminated.
*** [.pio\build\heltec-v4-raamses\lib0ce\Wire\Wire.cpp.o] Error 1
In file included from .pio/libdeps/heltec-v4-raamses/ESP8266 and ESP32 OLED driver for SSD1306 displays/src/OLEDDisplay.h:38,
                 from .pio/libdeps/heltec-v4-raamses/ESP8266 and ESP32 OLED driver for SSD1306 displays/src/OLEDDisplay.cpp:38:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/cores/esp32/Arduino.h:43:10: fatal error: pins_arduino.h: No such file or directory

**********************************************************************
* Looking for pins_arduino.h dependency? Check our library registry!
*
* CLI  > platformio lib search "header:pins_arduino.h"
* Web  > https://registry.platformio.org/search?q=header:pins_arduino.h
*
**********************************************************************

   43 | #include "pins_arduino.h"
      |          ^~~~~~~~~~~~~~~~
compilation terminated.
*** [.pio\build\heltec-v4-raamses\libee4\ESP8266 and ESP32 OLED driver for SSD1306 displays\OLEDDisplay.cpp.o] Error 1
In file included from .pio/libdeps/heltec-v4-raamses/ESP8266 and ESP32 OLED driver for SSD1306 displays/src/OLEDDisplayFonts.h:5,
                 from .pio/libdeps/heltec-v4-raamses/ESP8266 and ESP32 OLED driver for SSD1306 displays/src/OLEDDisplayFonts.cpp:1:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/cores/esp32/Arduino.h:43:10: fatal error: pins_arduino.h: No such file or directory

**********************************************************************
* Looking for pins_arduino.h dependency? Check our library registry!
*
* CLI  > platformio lib search "header:pins_arduino.h"
* Web  > https://registry.platformio.org/search?q=header:pins_arduino.h
*
**********************************************************************

   43 | #include "pins_arduino.h"
      |          ^~~~~~~~~~~~~~~~
compilation terminated.
*** [.pio\build\heltec-v4-raamses\libee4\ESP8266 and ESP32 OLED driver for SSD1306 displays\OLEDDisplayFonts.cpp.o] Error 1
In file included from .pio/libdeps/heltec-v4-raamses/ESP8266 and ESP32 OLED driver for SSD1306 displays/src/OLEDDisplayUi.h:36,
                 from .pio/libdeps/heltec-v4-raamses/ESP8266 and ESP32 OLED driver for SSD1306 displays/src/OLEDDisplayUi.cpp:32:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/cores/esp32/Arduino.h:43:10: fatal error: pins_arduino.h: No such file or directory

**********************************************************************
* Looking for pins_arduino.h dependency? Check our library registry!
*
* CLI  > platformio lib search "header:pins_arduino.h"
* Web  > https://registry.platformio.org/search?q=header:pins_arduino.h
*
**********************************************************************

   43 | #include "pins_arduino.h"
      |          ^~~~~~~~~~~~~~~~
compilation terminated.
*** [.pio\build\heltec-v4-raamses\libee4\ESP8266 and ESP32 OLED driver for SSD1306 displays\OLEDDisplayUi.cpp.o] Error 1
In file included from .pio/libdeps/heltec-v4-raamses/OneButton/src/OneButton.h:28,
                 from .pio/libdeps/heltec-v4-raamses/OneButton/src/OneButton.cpp:19:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/cores/esp32/Arduino.h:43:10: fatal error: pins_arduino.h: No such file or directory

**********************************************************************
* Looking for pins_arduino.h dependency? Check our library registry!
*
* CLI  > platformio lib search "header:pins_arduino.h"
* Web  > https://registry.platformio.org/search?q=header:pins_arduino.h
*
**********************************************************************

   43 | #include "pins_arduino.h"
      |          ^~~~~~~~~~~~~~~~
compilation terminated.
*** [.pio\build\heltec-v4-raamses\libf35\OneButton\OneButton.cpp.o] Error 1
=========================================================================================== [FAILED] Took 43.32 seconds ===========================================================================================

Environment        Status    Duration
-----------------  --------  ------------
heltec-v4-raamses  FAILED    00:00:43.315
====================================================================================== 1 failed, 0 succeeded in 00:00:43.315 ======================================================================================
PS C:\GitHub\RaamsesMesh\RaamsesMesh>