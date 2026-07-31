
Compiling .pio\build\heltec-v3-raamses\src\modules\Modules.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\NeighborInfoModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\NodeInfoModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\OnScreenKeyboardModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\PositionModule.cpp.o
src/mesh/aes-ccm.cpp: In function 'int constant_time_compare(const void*, const void*, size_t)':
src/mesh/aes-ccm.cpp:24:42: warning: type qualifiers ignored on cast result type [-Wignored-qualifiers]
   24 |     const volatile uint8_t *volatile a = (const volatile uint8_t *volatile)a_;
      |                                          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/mesh/aes-ccm.cpp:25:42: warning: type qualifiers ignored on cast result type [-Wignored-qualifiers]
   25 |     const volatile uint8_t *volatile b = (const volatile uint8_t *volatile)b_;
      |                                          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Compiling .pio\build\heltec-v3-raamses\src\modules\PowerStressModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\RangeTestModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\RemoteHardwareModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\ReplyBotModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\ReplyModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\RoutingModule.cpp.o
In file included from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32-libs/esp32s3/include/lwip/include/lwip/netdb.h:9,
                 from .pio/libdeps/heltec-v3-raamses/esp32_https_server/src/HTTPServer.hpp:11,
                 from .pio/libdeps/heltec-v3-raamses/esp32_https_server/src/HTTPSServer.hpp:16,
                 from src/mesh/http/WebServer.cpp:44:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32-libs/esp32s3/include/lwip/lwip/src/include/lwip/netdb.h:75:9: warning: "NO_DATA" redefined
   75 | #define NO_DATA         211
      |         ^~~~~~~
In file included from .pio/libdeps/heltec-v3-raamses/DFRobot_BMM150/DFRobot_BMM150.h:13,
                 from src/motion/BMM150Sensor.h:10,
                 from src/motion/AccelerometerThread.h:16,
                 from src/main.h:75,
                 from src/mesh/http/WebServer.cpp:5:
.pio/libdeps/heltec-v3-raamses/DFRobot_BMM150/bmm150_defs.h:430:9: note: this is the location of the previous definition
  430 | #define NO_DATA                          -32768
      |         ^~~~~~~
In file included from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32-libs/esp32s3/include/lwip/include/lwip/netdb.h:9,
                 from .pio/libdeps/heltec-v3-raamses/esp32_https_server/src/HTTPServer.hpp:11,
                 from .pio/libdeps/heltec-v3-raamses/esp32_https_server/src/HTTPSServer.hpp:16,
                 from src/mesh/http/ContentHandler.cpp:41:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32-libs/esp32s3/include/lwip/lwip/src/include/lwip/netdb.h:75:9: warning: "NO_DATA" redefined
   75 | #define NO_DATA         211
      |         ^~~~~~~
In file included from .pio/libdeps/heltec-v3-raamses/DFRobot_BMM150/DFRobot_BMM150.h:13,
                 from src/motion/BMM150Sensor.h:10,
                 from src/motion/AccelerometerThread.h:16,
                 from src/main.h:75,
                 from src/mesh/http/ContentHandler.cpp:6:
.pio/libdeps/heltec-v3-raamses/DFRobot_BMM150/bmm150_defs.h:430:9: note: this is the location of the previous definition
  430 | #define NO_DATA                          -32768
      |         ^~~~~~Compiling .pio\build\heltec-v3-raamses\src\modules\SerialModule.cpp.o
~
Compiling .pio\build\heltec-v3-raamses\src\modules\StatusLEDModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\StatusMessageModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\StoreForwardModule.cpp.o
src/modules/CannedMessageModule.cpp: In member function 'virtual void CannedMessageModule::drawFrame(OLEDDisplay*, OLEDDisplayUiState*, int16_t, int16_t)':
src/modules/CannedMessageModule.cpp:2055:17: warning: unused variable 'textYOffset' [-Wunused-variable]
 2055 |             int textYOffset = (rowHeight - FONT_HEIGHT_SMALL) / 2;
      |                 ^~~~~~~~~~~
src/modules/CannedMessageModule.cpp: In member function 'virtual ProcessMessage CannedMessageModule::handleReceived(const meshtastic_MeshPacket&)':
src/modules/CannedMessageModule.cpp:2233:35: warning: the address of 'nodeName' will never be NULL [-Waddress]
 2233 |                                  (nodeName && nodeName[0]) ? nodeName : "unknown", qualityLabel);
      |                                   ^~~~~~~~
src/modules/CannedMessageModule.cpp:2205:22: note: 'nodeName' declared here
 2205 |                 char nodeName[48];
      |                      ^~~~~~~~
src/modules/CannedMessageModule.cpp:2238:31: warning: the address of 'nodeName' will never be NULL [-Waddress]
 2238 |                              (nodeName && nodeName[0]) ? nodeName : "unknown", qualityLabel);
      |                               ^~~~~~~~
src/modules/CannedMessageModule.cpp:2205:22: note: 'nodeName' declared here
 2205 |                 char nodeName[48];
      |                      ^~~~~~~~
src/modules/CannedMessageModule.cpp:2244:74: warning: the address of 'nodeName' will never be NULL [-Waddress]
 2244 |                         snprintf(buf, sizeof(buf), "DM failed to\n@%s", (nodeName && nodeName[0]) ? nodeName : "unknown");
      |                                                                          ^~~~~~~~
src/modules/CannedMessageModule.cpp:2205:22: note: 'nodeName' declared here
 2205 |                 char nodeName[48];
      |                      ^~~~~~~~
Compiling .pio\build\heltec-v3-raamses\src\modules\SystemCommandsModule.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\AirQualityTelemetry.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\DeviceTelemetry.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\EnvironmentTelemetry.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\HealthTelemetry.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\HostMetrics.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\PowerTelemetry.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\Sensor\AHT10.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\Sensor\BH1750Sensor.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\Sensor\BME280Sensor.cpp.o
<command-line>: error: expected identifier before numeric constant
src/modules/esp32/RaamsesProto.h:50:5: note: in expansion of macro 'HELTEC_V3'
   50 |     HELTEC_V3    = 0x01,
      |     ^~~~~~~~~
<command-line>: error: expected '}' before numeric constant
src/modules/esp32/RaamsesProto.h:50:5: note: in expansion of macro 'HELTEC_V3'
   50 |     HELTEC_V3    = 0x01,
      |     ^~~~~~~~~
In file included from src/modules/esp32/RaamsesModule.h:7,
                 from src/modules/Modules.cpp:95:
src/modules/esp32/RaamsesProto.h:49:27: note: to match this '{'
   49 | enum DeviceType : uint8_t {
      |                           ^
<command-line>: error: expected unqualified-id before numeric constant
src/modules/esp32/RaamsesProto.h:50:5: note: in expansion of macro 'HELTEC_V3'
   50 |     HELTEC_V3    = 0x01,
      |     ^~~~~~~~~
src/modules/esp32/RaamsesProto.h:57:25: error: 'OK' conflicts with a previous declaration
   57 |     OK                = 0x00,
      |                         ^~~~
In file included from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/cores/esp32/esp32-hal-log.h:23,
                 from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/cores/esp32/esp32-hal.h:112,
                 from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/cores/esp32/Arduino.h:44,
                 from src/configuration.h:27,
                 from src/modules/Modules.cpp:1:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32-libs/esp32s3/include/esp_rom/esp32s3/include/esp32s3/rom/ets_sys.h:552:5: note: previous declaration 'STATUS OK'
  552 |     OK = 0,
      |     ^~
src/modules/esp32/RaamsesProto.h: In function 'uint8_t buildAlert(uint8_t*, uint8_t, uint16_t)':
src/modules/esp32/RaamsesProto.h:85:14: error: 'ALERT' was not declared in this scope; did you mean 'RaamsesProto::ALERT'?
   85 |     buf[0] = ALERT;
      |              ^~~~~
      |              RaamsesProto::ALERT
src/modules/esp32/RaamsesProto.h:40:5: note: 'RaamsesProto::ALERT' declared here
   40 |     ALERT     = 0x01,  // agent needs help
      |     ^~~~~
src/modules/esp32/RaamsesProto.h: In function 'uint8_t buildAck(uint8_t*, uint8_t)':
src/modules/esp32/RaamsesProto.h:93:14: error: 'ACK' was not declared in this scope; did you mean 'RaamsesProto::ACK'?
   93 |     buf[0] = ACK;
      |              ^~~
      |              RaamsesProto::ACK
src/modules/esp32/RaamsesProto.h:41:5: note: 'RaamsesProto::ACK' declared here
   41 |     ACK       = 0x02,  // acknowledge receipt
      |     ^~~
src/modules/esp32/RaamsesProto.h: In function 'uint8_t buildClear(uint8_t*, uint8_t, uint16_t)':
src/modules/esp32/RaamsesProto.h:100:14: error: 'CLEAR' was not declared in this scope; did you mean 'RaamsesProto::CLEAR'?
  100 |     buf[0] = CLEAR;
      |              ^~~~~
      |              RaamsesProto::CLEAR
src/modules/esp32/RaamsesProto.h:42:5: note: 'RaamsesProto::CLEAR' declared here
   42 |     CLEAR     = 0x03,  // alert resolved
      |     ^~~~~
src/modules/esp32/RaamsesProto.h: In function 'uint8_t buildHeartbeat(uint8_t*, uint32_t, uint8_t)':
src/modules/esp32/RaamsesProto.h:108:14: error: 'HEARTBEAT' was not declared in this scope; did you mean 'RaamsesProto::HEARTBEAT'?
  108 |     buf[0] = HEARTBEAT;
      |              ^~~~~~~~~
      |              RaamsesProto::HEARTBEAT
src/modules/esp32/RaamsesProto.h:43:5: note: 'RaamsesProto::HEARTBEAT' declared here
   43 |     HEARTBEAT = 0x04,  // periodic keepalive
      |     ^~~~~~~~~
src/modules/esp32/RaamsesProto.h: In function 'uint8_t buildRegister(uint8_t*, uint32_t, uint8_t, uint16_t)':
src/modules/esp32/RaamsesProto.h:116:14: error: 'REGISTER' was not declared in this scope; did you mean 'RaamsesProto::REGISTER'?
  116 |     buf[0] = REGISTER;
      |              ^~~~~~~~
      |              RaamsesProto::REGISTER
src/modules/esp32/RaamsesProto.h:44:5: note: 'RaamsesProto::REGISTER' declared here
   44 |     REGISTER  = 0x05,  // device registration
      |     ^~~~~~~~
src/modules/esp32/RaamsesProto.h: In function 'uint8_t buildBuzz(uint8_t*, uint8_t)':
src/modules/esp32/RaamsesProto.h:125:14: error: 'BUZZ' was not declared in this scope; did you mean 'RaamsesProto::BUZZ'?
  125 |     buf[0] = BUZZ;
      |              ^~~~
      |              RaamsesProto::BUZZ
src/modules/esp32/RaamsesProto.h:45:5: note: 'RaamsesProto::BUZZ' declared here
   45 |     BUZZ      = 0x06,  // test buzzer/LED
      |     ^~~~
src/modules/esp32/RaamsesProto.h: In function 'const char* cmdName(uint8_t)':
src/modules/esp32/RaamsesProto.h:144:10: error: 'ALERT' was not declared in this scope; did you mean 'RaamsesProto::ALERT'?
  144 |     case ALERT:     return "ALERT";
      |          ^~~~~
      |          RaamsesProto::ALERT
src/modules/esp32/RaamsesProto.h:40:5: note: 'RaamsesProto::ALERT' declared here
   40 |     ALERT     = 0x01,  // agent needs help
      |     ^~~~~
src/modules/esp32/RaamsesProto.h:145:10: error: 'ACK' was not declared in this scope; did you mean 'RaamsesProto::ACK'?
  145 |     case ACK:       return "ACK";
      |          ^~~
      |          RaamsesProto::ACK
src/modules/esp32/RaamsesProto.h:41:5: note: 'RaamsesProto::ACK' declared here
   41 |     ACK       = 0x02,  // acknowledge receipt
      |     ^~~
src/modules/esp32/RaamsesProto.h:146:10: error: 'CLEAR' was not declared in this scope; did you mean 'RaamsesProto::CLEAR'?
  146 |     case CLEAR:     return "CLEAR";
      |          ^~~~~
      |          RaamsesProto::CLEAR
src/modules/esp32/RaamsesProto.h:42:5: note: 'RaamsesProto::CLEAR' declared here
   42 |     CLEAR     = 0x03,  // alert resolved
      |     ^~~~~
src/modules/esp32/RaamsesProto.h:147:10: error: 'HEARTBEAT' was not declared in this scope; did you mean 'RaamsesProto::HEARTBEAT'?
  147 |     case HEARTBEAT: return "HEARTBEAT";
      |          ^~~~~~~~~
      |          RaamsesProto::HEARTBEAT
src/modules/esp32/RaamsesProto.h:43:5: note: 'RaamsesProto::HEARTBEAT' declared here
   43 |     HEARTBEAT = 0x04,  // periodic keepalive
      |     ^~~~~~~~~
src/modules/esp32/RaamsesProto.h:148:10: error: 'REGISTER' was not declared in this scope; did you mean 'RaamsesProto::REGISTER'?
  148 |     case REGISTER:  return "REGISTER";
      |          ^~~~~~~~
      |          RaamsesProto::REGISTER
src/modules/esp32/RaamsesProto.h:44:5: note: 'RaamsesProto::REGISTER' declared here
   44 |     REGISTER  = 0x05,  // device registration
      |     ^~~~~~~~
src/modules/esp32/RaamsesProto.h:149:10: error: 'BUZZ' was not declared in this scope; did you mean 'RaamsesProto::BUZZ'?
  149 |     case BUZZ:      return "BUZZ";
      |          ^~~~
      |          RaamsesProto::BUZZ
src/modules/esp32/RaamsesProto.h:45:5: note: 'RaamsesProto::BUZZ' declared here
   45 |     BUZZ      = 0x06,  // test buzzer/LED
      |     ^~~~
src/modules/esp32/RaamsesProto.h: In function 'const char* deviceTypeName(uint8_t)':
src/modules/esp32/RaamsesProto.h:157:10: error: 'HELTEC_V4' was not declared in this scope; did you mean 'HELTEC_V3'?
  157 |     case HELTEC_V4:    return "heltec_v4";
      |          ^~~~~~~~~
      |          HELTEC_V3
src/modules/esp32/RaamsesProto.h:158:10: error: 'THINKNODE_M2' was not declared in this scope
  158 |     case THINKNODE_M2: return "thinknode_m2";
      |          ^~~~~~~~~~~~
src/modules/esp32/RaamsesProto.h: At global scope:
src/modules/esp32/RaamsesProto.h:163:1: error: expected declaration before '}' token
  163 | } // namespace RaamsesProto
      | ^
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\Sensor\BME680Sensor.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\Sensor\BMP085Sensor.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\Sensor\BMP280Sensor.cpp.o
Compiling .pio\build\heltec-v3-raamses\src\modules\Telemetry\Sensor\BMP3XXSensor.cpp.o
*** [.pio\build\heltec-v3-raamses\src\modules\Modules.cpp.o] Error 1
===
====================== [FAILED] Took 163.01 seconds =========================
Environment        Status    Duration
-----------------  --------  ------------
heltec-v3-raamses  FAILED    00:02:43.006
==================== 1 failed, 0 succeeded in 00:02:43.006 ====================
*** Error 1
*** Original Arduino "idf_component.yml" restored ***
*** [checkprogsize] Explicit exit, status 1
========================================================================================== [FAILED] Took 441.03 seconds ==========================================================================================

Environment        Status    Duration
-----------------  --------  ------------
heltec-v3-raamses  FAILED    00:07:21.031
====================================================================================== 1 failed, 0 succeeded in 00:07:21.031 ======================================================================================
PS C:\GitHub\RaamsesMesh\RaamsesMesh>