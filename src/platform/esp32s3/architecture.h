#pragma once

#define ARCH_ESP32

#ifndef HAS_BUTTON
#define HAS_BUTTON 1
#endif
#ifndef HAS_TELEMETRY
#define HAS_TELEMETRY 1
#endif
#ifndef HAS_SCREEN
#define HAS_SCREEN 1
#endif
#ifndef HAS_WIRE
#define HAS_WIRE 1
#endif
#ifndef HAS_SENSOR
#define HAS_SENSOR 1
#endif
#ifndef HAS_RADIO
#define HAS_RADIO 1
#endif

#if defined(HELTEC_V3)
#define HW_VENDOR meshtastic_HardwareModel_HELTEC_V3
#elif defined(HELTEC_V4)
#define HW_VENDOR meshtastic_HardwareModel_HELTEC_V4
#elif defined(THINKNODE_M2)
#define HW_VENDOR meshtastic_HardwareModel_PRIVATE_HW
#endif
