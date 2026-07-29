
PS C:\GitHub\RaamsesMesh\RaamsesMesh> pio run -e thinknode-m2-raamses -t upload --upload-port COM25
Processing thinknode-m2-raamses (board: ESP32-S3-WROOM-1-N4; platform:
https://github.com/meshtastic/pioarduino-platform-espressif32/archive/refs/heads/55.03.39.zip; framework: arduino)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Verbose mode can be enabled via `-v, --verbose` option
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
*** Compile Arduino IDF libs for thinknode-m2-raamses ***
*** "custom_component" is used to deselect managed idf components ***
[ComponentManager] Created backup of build file
[ComponentManager] Component not found: espressif/esp_hosted
[ComponentManager] Component not found: espressif/esp_wifi_remote
[ComponentManager] Component not found: espressif/esp_modem
[ComponentManager] Component not found: espressif/esp-dsp
[ComponentManager] Component not found: espressif/esp32-camera
[ComponentManager] Component not found: espressif/libsodium
[ComponentManager] Component not found: espressif/esp-modbus
[ComponentManager] Component not found: espressif/qrcode
[ComponentManager] Component not found: espressif/esp_insights
[ComponentManager] Component not found: espressif/esp_diag_data_store
[ComponentManager] Component not found: espressif/esp_diagnostics
[ComponentManager] Component not found: espressif/esp_rainmaker
[ComponentManager] Component not found: espressif/rmaker_common
[ComponentManager] Component not found: chmorgan/esp-libhelix-mp3
[ComponentManager] Component not found: espressif/esp-tflite-micro
[ComponentManager] Component not found: espressif/esp-sr
[ComponentManager] Component not found: espressif/esp_matter
[ComponentManager] Component not found: espressif/esp-zboss-lib
[ComponentManager] Component not found: espressif/esp-zigbee-lib
[ComponentManager] Component not found: espressif/mqtt
[ComponentManager] BT/BLE protection enabled
[ComponentManager] Protected BT library: nimble-arduino
[ComponentManager] Protected BT library: bt
[ComponentManager] Processed 15 ignored libraries
[ComponentManager] Session completed with 25 changes
*** Add "custom_sdkconfig" settings to IDF sdkconfig.defaults ***
Info: Unified frequency mode (>= 80MHz): 80MHz for both Flash and PSRAM
Replace: # CONFIG_BOOTLOADER_LOG_LEVEL_NONE is not set with: CONFIG_BOOTLOADER_LOG_LEVEL_NONE=y
Replace: CONFIG_ESPTOOLPY_FLASHMODE_QIO=y with: CONFIG_ESPTOOLPY_FLASHMODE_QIO=y
Replace: # CONFIG_ESPTOOLPY_FLASHMODE_QOUT is not set with: # CONFIG_ESPTOOLPY_FLASHMODE_QOUT is not set
Replace: # CONFIG_ESPTOOLPY_FLASHMODE_DIO is not set with: # CONFIG_ESPTOOLPY_FLASHMODE_DIO is not set
Replace: # CONFIG_ESPTOOLPY_FLASHMODE_DOUT is not set with: # CONFIG_ESPTOOLPY_FLASHMODE_DOUT is not set
Replace: # CONFIG_ESPTOOLPY_FLASHFREQ_120M is not set with: # CONFIG_ESPTOOLPY_FLASHFREQ_120M is not set
Replace: CONFIG_ESPTOOLPY_FLASHFREQ_80M=y with: CONFIG_ESPTOOLPY_FLASHFREQ_80M=y
Replace: # CONFIG_ESPTOOLPY_FLASHFREQ_40M is not set with: # CONFIG_ESPTOOLPY_FLASHFREQ_40M is not set
Replace: # CONFIG_ESPTOOLPY_FLASHFREQ_20M is not set with: # CONFIG_ESPTOOLPY_FLASHFREQ_20M is not set
Replace: CONFIG_ESPTOOLPY_FLASHFREQ="80m" with: CONFIG_ESPTOOLPY_FLASHFREQ="80m"
Replace: # CONFIG_ESPTOOLPY_FLASHSIZE_4MB is not set with: CONFIG_ESPTOOLPY_FLASHSIZE_4MB=y
Replace: # CONFIG_ESPTOOLPY_FLASHSIZE_8MB is not set with: # CONFIG_ESPTOOLPY_FLASHSIZE_8MB is not set
Replace: CONFIG_ESPTOOLPY_FLASHSIZE_16MB=y with: # CONFIG_ESPTOOLPY_FLASHSIZE_16MB is not set
Replace: # CONFIG_ESPTOOLPY_FLASHSIZE_32MB is not set with: # CONFIG_ESPTOOLPY_FLASHSIZE_32MB is not set
Replace: # CONFIG_ESPTOOLPY_FLASHSIZE_64MB is not set with: # CONFIG_ESPTOOLPY_FLASHSIZE_64MB is not set
Replace: # CONFIG_ESPTOOLPY_FLASHSIZE_128MB is not set with: # CONFIG_ESPTOOLPY_FLASHSIZE_128MB is not set
Replace: CONFIG_ESPTOOLPY_FLASHSIZE="16MB" with: CONFIG_ESPTOOLPY_FLASHSIZE="4MB"
Replace: # CONFIG_ARDUHAL_LOG_COLORS is not set with: CONFIG_ARDUHAL_LOG_COLORS=y
Replace: # CONFIG_ARDUINO_SELECTIVE_COMPILATION is not set with: CONFIG_ARDUINO_SELECTIVE_COMPILATION=y
Replace: CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_ENABLE=y with: CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_ENABLE=n
Replace: # CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_DISABLE is not set with: CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_DISABLE=y
Replace: CONFIG_COMPILER_CXX_EXCEPTIONS=y with: CONFIG_COMPILER_CXX_EXCEPTIONS=n
Replace: # CONFIG_COMPILER_STACK_CHECK_MODE_NONE is not set with: CONFIG_COMPILER_STACK_CHECK_MODE_NONE=y
Replace: CONFIG_COMPILER_STACK_CHECK_MODE_NORM=y with: CONFIG_COMPILER_STACK_CHECK_MODE_NORM=n
Replace: # CONFIG_COMPILER_DISABLE_GCC12_WARNINGS is not set with: CONFIG_COMPILER_DISABLE_GCC12_WARNINGS=y
Replace: # CONFIG_COMPILER_DISABLE_GCC13_WARNINGS is not set with: CONFIG_COMPILER_DISABLE_GCC13_WARNINGS=y
Replace: # CONFIG_COMPILER_DISABLE_GCC14_WARNINGS is not set with: CONFIG_COMPILER_DISABLE_GCC14_WARNINGS=y
Replace: CONFIG_COMPILER_ORPHAN_SECTIONS_WARNING=y with: CONFIG_COMPILER_ORPHAN_SECTIONS_WARNING=n
Replace: # CONFIG_COMPILER_ORPHAN_SECTIONS_PLACE is not set with: CONFIG_COMPILER_ORPHAN_SECTIONS_PLACE=y
Replace: CONFIG_BT_ENABLED=y with: CONFIG_BT_ENABLED=y
Replace: # CONFIG_BT_BLUEDROID_ENABLED is not set with: CONFIG_BT_BLUEDROID_ENABLED=n
Replace: CONFIG_BT_NIMBLE_ENABLED=y with: CONFIG_BT_NIMBLE_ENABLED=y
Replace: CONFIG_BT_CONTROLLER_ENABLED=y with: CONFIG_BT_CONTROLLER_ENABLED=y
Replace: CONFIG_BT_NIMBLE_HOST_TASK_STACK_SIZE=5120 with: CONFIG_BT_NIMBLE_HOST_TASK_STACK_SIZE=5120
Replace: CONFIG_BT_NIMBLE_ROLE_CENTRAL=y with: CONFIG_BT_NIMBLE_ROLE_CENTRAL=n
Replace: CONFIG_BT_NIMBLE_ROLE_OBSERVER=y with: CONFIG_BT_NIMBLE_ROLE_OBSERVER=n
Replace: CONFIG_BT_NIMBLE_NVS_PERSIST=y with: CONFIG_BT_NIMBLE_NVS_PERSIST=y
Replace: CONFIG_BT_NIMBLE_MAX_BONDS=3 with: CONFIG_BT_NIMBLE_MAX_BONDS=6
Replace: CONFIG_BT_NIMBLE_WHITELIST_SIZE=12 with: CONFIG_BT_NIMBLE_WHITELIST_SIZE=1
Replace: CONFIG_BT_NIMBLE_MAX_CONNECTIONS=3 with: CONFIG_BT_NIMBLE_MAX_CONNECTIONS=1
Replace: CONFIG_BT_NIMBLE_MAX_CCCDS=8 with: CONFIG_BT_NIMBLE_MAX_CCCDS=8
Replace: CONFIG_BT_NIMBLE_MSYS_1_BLOCK_COUNT=12 with: CONFIG_BT_NIMBLE_MSYS_1_BLOCK_COUNT=12
Replace: CONFIG_BT_NIMBLE_MSYS_2_BLOCK_COUNT=24 with: CONFIG_BT_NIMBLE_MSYS_2_BLOCK_COUNT=8
Replace: CONFIG_BT_NIMBLE_TRANSPORT_ACL_FROM_LL_COUNT=24 with: CONFIG_BT_NIMBLE_TRANSPORT_ACL_FROM_LL_COUNT=8
Replace: CONFIG_BT_NIMBLE_TRANSPORT_EVT_COUNT=30 with: CONFIG_BT_NIMBLE_TRANSPORT_EVT_COUNT=12
Replace: CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_2M_PHY=y with: CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_2M_PHY=n
Replace: # CONFIG_BT_NIMBLE_EXT_ADV is not set with: CONFIG_BT_NIMBLE_EXT_ADV=n
Replace: # CONFIG_BT_NIMBLE_EXT_SCAN is not set with: CONFIG_BT_NIMBLE_EXT_SCAN=n
Replace: CONFIG_BT_NIMBLE_PROX_SERVICE=y with: CONFIG_BT_NIMBLE_PROX_SERVICE=n
Replace: CONFIG_BT_NIMBLE_ANS_SERVICE=y with: CONFIG_BT_NIMBLE_ANS_SERVICE=n
Replace: CONFIG_BT_NIMBLE_CTS_SERVICE=y with: CONFIG_BT_NIMBLE_CTS_SERVICE=n
Replace: CONFIG_BT_NIMBLE_HTP_SERVICE=y with: CONFIG_BT_NIMBLE_HTP_SERVICE=n
Replace: CONFIG_BT_NIMBLE_IPSS_SERVICE=y with: CONFIG_BT_NIMBLE_IPSS_SERVICE=n
Replace: CONFIG_BT_NIMBLE_TPS_SERVICE=y with: CONFIG_BT_NIMBLE_TPS_SERVICE=n
Replace: CONFIG_BT_NIMBLE_IAS_SERVICE=y with: CONFIG_BT_NIMBLE_IAS_SERVICE=n
Replace: CONFIG_BT_NIMBLE_LLS_SERVICE=y with: CONFIG_BT_NIMBLE_LLS_SERVICE=n
Replace: CONFIG_BT_NIMBLE_SPS_SERVICE=y with: CONFIG_BT_NIMBLE_SPS_SERVICE=y
Replace: CONFIG_BT_NIMBLE_HR_SERVICE=y with: CONFIG_BT_NIMBLE_HR_SERVICE=n
Replace: # CONFIG_BT_NIMBLE_HID_SERVICE is not set with: CONFIG_BT_NIMBLE_HID_SERVICE=n
Replace: CONFIG_BT_NIMBLE_BAS_SERVICE=y with: CONFIG_BT_NIMBLE_BAS_SERVICE=n
Replace: CONFIG_BT_NIMBLE_DIS_SERVICE=y with: CONFIG_BT_NIMBLE_DIS_SERVICE=n
Replace: # CONFIG_BT_NIMBLE_BLUFI_ENABLE is not set with: CONFIG_BT_NIMBLE_BLUFI_ENABLE=n
Replace: # CONFIG_BT_NIMBLE_LOG_LEVEL_ERROR is not set with: CONFIG_BT_NIMBLE_LOG_LEVEL_ERROR=y
Replace: CONFIG_BT_NIMBLE_LOG_LEVEL_INFO=y with: # CONFIG_BT_NIMBLE_LOG_LEVEL_INFO is not set
Replace: CONFIG_BT_CTRL_BLE_MAX_ACT=6 with: CONFIG_BT_CTRL_BLE_MAX_ACT=2
Replace: CONFIG_BT_CTRL_SCAN_DUPL_CACHE_SIZE=100 with: CONFIG_BT_CTRL_SCAN_DUPL_CACHE_SIZE=10
Replace: CONFIG_BLE_MESH=y with: CONFIG_BLE_MESH=n
Replace: CONFIG_ETH_ENABLED=y with: CONFIG_ETH_ENABLED=n
Replace: CONFIG_ESP_GDBSTUB_ENABLED=y with: CONFIG_ESP_GDBSTUB_ENABLED=n
Replace: CONFIG_ESP_HTTP_CLIENT_ENABLE_HTTPS=y with: CONFIG_ESP_HTTP_CLIENT_ENABLE_HTTPS=n
Replace: CONFIG_ESP_HTTP_CLIENT_ENABLE_BASIC_AUTH=y with: CONFIG_ESP_HTTP_CLIENT_ENABLE_BASIC_AUTH=n
Replace: CONFIG_HTTPD_WS_SUPPORT=y with: CONFIG_HTTPD_WS_SUPPORT=n
Replace: CONFIG_ESP_HTTPS_SERVER_ENABLE=y with: CONFIG_ESP_HTTPS_SERVER_ENABLE=n
Replace: CONFIG_SPIRAM=y with: # CONFIG_SPIRAM is not set
Replace: # CONFIG_RINGBUF_PLACE_FUNCTIONS_INTO_FLASH is not set with: CONFIG_RINGBUF_PLACE_FUNCTIONS_INTO_FLASH=y
Replace: # CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_80 is not set with: # CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_80 is not set
Replace: # CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_160 is not set with: # CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_160 is not set
Replace: CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_240=y with: CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ_240=y
Replace: CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ=240 with: CONFIG_ESP_DEFAULT_CPU_FREQ_MHZ=240
Replace: CONFIG_ESP_TASK_WDT_INIT=y with: CONFIG_ESP_TASK_WDT_INIT=n
Replace: # CONFIG_ESP_WIFI_IRAM_OPT is not set with: CONFIG_ESP_WIFI_IRAM_OPT=n
Replace: CONFIG_ESP_WIFI_ENABLE_WPA3_SAE=y with: CONFIG_ESP_WIFI_ENABLE_WPA3_SAE=n
Replace: CONFIG_ESP_WIFI_ENABLE_SAE_H2E=y with: CONFIG_ESP_WIFI_ENABLE_SAE_H2E=n
Replace: CONFIG_ESP_WIFI_ENABLE_WPA3_OWE_STA=y with: CONFIG_ESP_WIFI_ENABLE_WPA3_OWE_STA=n
Replace: CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT=y with: CONFIG_ESP_WIFI_ENTERPRISE_SUPPORT=n
Replace: CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH=y with: CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH=n
Replace: # CONFIG_ESP_COREDUMP_ENABLE_TO_NONE is not set with: CONFIG_ESP_COREDUMP_ENABLE_TO_NONE=y
Replace: CONFIG_ESP_COREDUMP_ENABLE=y with: CONFIG_ESP_COREDUMP_ENABLE=n
Replace: CONFIG_FREERTOS_USE_TRACE_FACILITY=y with: CONFIG_FREERTOS_USE_TRACE_FACILITY=n
Replace: CONFIG_FREERTOS_USE_STATS_FORMATTING_FUNCTIONS=y with: CONFIG_FREERTOS_USE_STATS_FORMATTING_FUNCTIONS=n
Replace: CONFIG_FREERTOS_GENERATE_RUN_TIME_STATS=y with: CONFIG_FREERTOS_GENERATE_RUN_TIME_STATS=n
Replace: # CONFIG_FREERTOS_PLACE_FUNCTIONS_INTO_FLASH is not set with: CONFIG_FREERTOS_PLACE_FUNCTIONS_INTO_FLASH=y
Replace: CONFIG_FREERTOS_PLACE_SNAPSHOT_FUNS_INTO_FLASH=y with: CONFIG_FREERTOS_PLACE_SNAPSHOT_FUNS_INTO_FLASH=y
Replace: # CONFIG_LOG_COLORS is not set with: CONFIG_LOG_COLORS=y
Replace: CONFIG_LWIP_IP_FORWARD=y with: CONFIG_LWIP_IP_FORWARD=n
Replace: CONFIG_LWIP_IPV4_NAPT=y with: CONFIG_LWIP_IPV4_NAPT=n
Replace: CONFIG_LWIP_PPP_SUPPORT=y with: CONFIG_LWIP_PPP_SUPPORT=n
Replace: CONFIG_MBEDTLS_SSL_MAX_CONTENT_LEN=16384 with: CONFIG_MBEDTLS_SSL_MAX_CONTENT_LEN=16384
Replace: CONFIG_MBEDTLS_SSL_KEEP_PEER_CERTIFICATE=y with: CONFIG_MBEDTLS_SSL_KEEP_PEER_CERTIFICATE=y
Replace: CONFIG_MBEDTLS_PKCS7_C=y with: CONFIG_MBEDTLS_PKCS7_C=n
Replace: CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEFAULT_FULL=y with: CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEFAULT_FULL=n
Replace: # CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEFAULT_CMN is not set with: CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_DEFAULT_CMN=y
Replace: CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_MAX_CERTS=200 with: CONFIG_MBEDTLS_CERTIFICATE_BUNDLE_MAX_CERTS=1
Replace: CONFIG_MBEDTLS_CMAC_C=y with: CONFIG_MBEDTLS_CMAC_C=n
Replace: CONFIG_MBEDTLS_SHA512_C=y with: CONFIG_MBEDTLS_SHA512_C=n
Replace: CONFIG_MBEDTLS_KEY_EXCHANGE_ECDHE_PSK=y with: CONFIG_MBEDTLS_KEY_EXCHANGE_ECDHE_PSK=n
Replace: CONFIG_MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA=y with: CONFIG_MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA=n
Replace: CONFIG_MBEDTLS_KEY_EXCHANGE_ECDH_RSA=y with: CONFIG_MBEDTLS_KEY_EXCHANGE_ECDH_RSA=n
Replace: CONFIG_MBEDTLS_KEY_EXCHANGE_ECJPAKE=y with: CONFIG_MBEDTLS_KEY_EXCHANGE_ECJPAKE=n
Replace: CONFIG_MBEDTLS_SSL_RENEGOTIATION=y with: CONFIG_MBEDTLS_SSL_RENEGOTIATION=y
Replace: CONFIG_MBEDTLS_SSL_PROTO_DTLS=y with: CONFIG_MBEDTLS_SSL_PROTO_DTLS=y
Replace: CONFIG_MBEDTLS_SSL_ALPN=y with: CONFIG_MBEDTLS_SSL_ALPN=y
Replace: CONFIG_MBEDTLS_CLIENT_SSL_SESSION_TICKETS=y with: CONFIG_MBEDTLS_CLIENT_SSL_SESSION_TICKETS=y
Replace: CONFIG_MBEDTLS_SERVER_SSL_SESSION_TICKETS=y with: CONFIG_MBEDTLS_SERVER_SSL_SESSION_TICKETS=y
Replace: CONFIG_MBEDTLS_CAMELLIA_C=y with: CONFIG_MBEDTLS_CAMELLIA_C=n
Replace: CONFIG_MBEDTLS_CCM_C=y with: CONFIG_MBEDTLS_CCM_C=n
Replace: CONFIG_MBEDTLS_X509_CRL_PARSE_C=y with: CONFIG_MBEDTLS_X509_CRL_PARSE_C=n
Replace: CONFIG_MBEDTLS_X509_CSR_PARSE_C=y with: CONFIG_MBEDTLS_X509_CSR_PARSE_C=n
Replace: CONFIG_MBEDTLS_ECP_DP_SECP192R1_ENABLED=y with: CONFIG_MBEDTLS_ECP_DP_SECP192R1_ENABLED=n
Replace: CONFIG_MBEDTLS_ECP_DP_SECP224R1_ENABLED=y with: CONFIG_MBEDTLS_ECP_DP_SECP224R1_ENABLED=n
Replace: CONFIG_MBEDTLS_ECP_DP_SECP384R1_ENABLED=y with: CONFIG_MBEDTLS_ECP_DP_SECP384R1_ENABLED=n
Replace: CONFIG_MBEDTLS_ECP_DP_SECP521R1_ENABLED=y with: CONFIG_MBEDTLS_ECP_DP_SECP521R1_ENABLED=n
Replace: CONFIG_MBEDTLS_ECP_DP_SECP192K1_ENABLED=y with: CONFIG_MBEDTLS_ECP_DP_SECP192K1_ENABLED=n
Replace: CONFIG_MBEDTLS_ECP_DP_SECP224K1_ENABLED=y with: CONFIG_MBEDTLS_ECP_DP_SECP224K1_ENABLED=n
Replace: CONFIG_MBEDTLS_ECP_DP_SECP256K1_ENABLED=y with: CONFIG_MBEDTLS_ECP_DP_SECP256K1_ENABLED=n
Replace: CONFIG_MBEDTLS_ECP_DP_BP256R1_ENABLED=y with: CONFIG_MBEDTLS_ECP_DP_BP256R1_ENABLED=n
Replace: CONFIG_MBEDTLS_ECP_DP_BP384R1_ENABLED=y with: CONFIG_MBEDTLS_ECP_DP_BP384R1_ENABLED=n
Replace: CONFIG_MBEDTLS_ECP_DP_BP512R1_ENABLED=y with: CONFIG_MBEDTLS_ECP_DP_BP512R1_ENABLED=n
Replace: # CONFIG_MBEDTLS_ALLOW_WEAK_CERTIFICATE_VERIFICATION is not set with: CONFIG_MBEDTLS_ALLOW_WEAK_CERTIFICATE_VERIFICATION=y
Replace: CONFIG_MQTT_PROTOCOL_311=y with: CONFIG_MQTT_PROTOCOL_311=n
Replace: CONFIG_MQTT_TRANSPORT_SSL=y with: CONFIG_MQTT_TRANSPORT_SSL=n
Replace: CONFIG_MQTT_TRANSPORT_WEBSOCKET=y with: CONFIG_MQTT_TRANSPORT_WEBSOCKET=n
Replace: CONFIG_MQTT_TRANSPORT_WEBSOCKET_SECURE=y with: CONFIG_MQTT_TRANSPORT_WEBSOCKET_SECURE=n
Replace: # CONFIG_OPENTHREAD_ENABLED is not set with: CONFIG_OPENTHREAD_ENABLED=n
Replace: CONFIG_WS_TRANSPORT=y with: CONFIG_WS_TRANSPORT=n
Replace: CONFIG_UNITY_ENABLE_FLOAT=y with: CONFIG_UNITY_ENABLE_FLOAT=n
Replace: CONFIG_UNITY_ENABLE_DOUBLE=y with: CONFIG_UNITY_ENABLE_DOUBLE=n
Replace: CONFIG_UNITY_ENABLE_IDF_TEST_RUNNER=y with: CONFIG_UNITY_ENABLE_IDF_TEST_RUNNER=n
Replace: CONFIG_VFS_SUPPORT_SELECT=y with: CONFIG_VFS_SUPPORT_SELECT=n
Replace: CONFIG_VFS_SUPPRESS_SELECT_DEBUG_OUTPUT=y with: CONFIG_VFS_SUPPRESS_SELECT_DEBUG_OUTPUT=n
Replace: CONFIG_VFS_SUPPORT_TERMIOS=y with: CONFIG_VFS_SUPPORT_TERMIOS=n
Replace: CONFIG_ZB_ENABLED=y with: CONFIG_ZB_ENABLED=n
Replace: CONFIG_ESP_INSIGHTS_ENABLED=y with: CONFIG_ESP_INSIGHTS_ENABLED=n
Replace: CONFIG_MDNS_ENABLE_CONSOLE_CLI=y with: CONFIG_MDNS_ENABLE_CONSOLE_CLI=n
Replace: CONFIG_MDNS_PREDEF_NETIF_AP=y with: CONFIG_MDNS_PREDEF_NETIF_AP=n
Replace: CONFIG_NETWORK_PROV_NETWORK_TYPE_WIFI=y with: CONFIG_NETWORK_PROV_NETWORK_TYPE_WIFI=n
Replace: # CONFIG_IDF_EXPERIMENTAL_FEATURES is not set with: CONFIG_IDF_EXPERIMENTAL_FEATURES=y
Replace: # CONFIG_ESP32S3_DEFAULT_CPU_FREQ_80 is not set with: # CONFIG_ESP32S3_DEFAULT_CPU_FREQ_80 is not set
Replace: # CONFIG_ESP32S3_DEFAULT_CPU_FREQ_160 is not set with: # CONFIG_ESP32S3_DEFAULT_CPU_FREQ_160 is not set
Replace: CONFIG_ESP32S3_DEFAULT_CPU_FREQ_240=y with: CONFIG_ESP32S3_DEFAULT_CPU_FREQ_240=y
Replace: # CONFIG_ESP32_WIFI_RX_IRAM_OPT is not set with: CONFIG_ESP32_WIFI_RX_IRAM_OPT=n
Replace: CONFIG_ESP32_ENABLE_COREDUMP=y with: CONFIG_ESP32_ENABLE_COREDUMP=n
Replace: CONFIG_PPP_SUPPORT=y with: CONFIG_PPP_SUPPORT=n
Replace: # CONFIG_NEWLIB_NANO_FORMAT is not set with: CONFIG_NEWLIB_NANO_FORMAT=y
Replace: CONFIG_SUPPORT_TERMIOS=y with: CONFIG_SUPPORT_TERMIOS=n
Add: # CONFIG_ESPTOOLPY_FLASHFREQ_26M is not set
Add: CONFIG_ESP_SYSTEM_ESP32_SRAM1_REGION_AS_IRAM=y
Add: CONFIG_SPIRAM_CACHE_LIBCHAR_IN_IRAM=n
Add: CONFIG_SPIRAM_CACHE_LIBSTR_IN_IRAM=n
Add: CONFIG_SPIRAM_CACHE_LIBMISC_IN_IRAM=n
Add: CONFIG_SPIRAM_CACHE_LIBTIME_IN_IRAM=n
Add: CONFIG_IEEE802154_ENABLED=n
Add: CONFIG_ARDUINO_SELECTIVE_Ethernet=n
Add: CONFIG_BTDM_CTRL_MODE_BLE_ONLY=y
Add: CONFIG_BT_NIMBLE_ENABLE_PERIODIC_SYNC=n
Add: CONFIG_BT_NIMBLE_ENABLE_PERIODIC_ADV=n
Add: CONFIG_BT_NIMBLE_PERIODIC_ADV_SYNC_TRANSFER=n
Add: CONFIG_ARDUINO_SELECTIVE_SPI=y
Add: CONFIG_ARDUINO_SELECTIVE_Wire=y
Add: CONFIG_ARDUINO_SELECTIVE_ESP_SR=n
Add: CONFIG_ARDUINO_SELECTIVE_EEPROM=y
Add: CONFIG_ARDUINO_SELECTIVE_Preferences=y
Add: CONFIG_ARDUINO_SELECTIVE_Ticker=y
Add: CONFIG_ARDUINO_SELECTIVE_Update=y
Add: CONFIG_ARDUINO_SELECTIVE_Zigbee=n
Add: CONFIG_ARDUINO_SELECTIVE_FS=y
Add: CONFIG_ARDUINO_SELECTIVE_SD=y
Add: CONFIG_ARDUINO_SELECTIVE_SD_MMC=y
Add: CONFIG_ARDUINO_SELECTIVE_SPIFFS=y
Add: CONFIG_ARDUINO_SELECTIVE_FFat=n
Add: CONFIG_ARDUINO_SELECTIVE_LittleFS=y
Add: CONFIG_ARDUINO_SELECTIVE_Network=y
Add: CONFIG_ARDUINO_SELECTIVE_PPP=n
Add: CONFIG_ARDUINO_SELECTIVE_Hash=y
Add: CONFIG_ARDUINO_SELECTIVE_ArduinoOTA=n
Add: CONFIG_ARDUINO_SELECTIVE_AsyncUDP=y
Add: CONFIG_ARDUINO_SELECTIVE_DNSServer=n
Add: CONFIG_ARDUINO_SELECTIVE_ESPmDNS=y
Add: CONFIG_ARDUINO_SELECTIVE_HTTPClient=n
Add: CONFIG_ARDUINO_SELECTIVE_Matter=n
Add: CONFIG_ARDUINO_SELECTIVE_NetBIOS=n
Add: CONFIG_ARDUINO_SELECTIVE_WebServer=n
Add: CONFIG_ARDUINO_SELECTIVE_WiFi=y
Add: CONFIG_ARDUINO_SELECTIVE_NetworkClientSecure=y
Add: CONFIG_ARDUINO_SELECTIVE_WiFiProv=n
Add: CONFIG_ARDUINO_SELECTIVE_BLE=y
Add: CONFIG_ARDUINO_SELECTIVE_BluetoothSerial=n
Add: CONFIG_ARDUINO_SELECTIVE_SimpleBLE=n
Add: CONFIG_ARDUINO_SELECTIVE_RainMaker=n
Add: CONFIG_ARDUINO_SELECTIVE_OpenThread=n
Add: CONFIG_ARDUINO_SELECTIVE_Insights=n
Using Python 3.14.5 environment at: C:\Users\seanr\.platformio\penv\.espidf-5.5.4
Warning: the 'src_filter' option cannot be used with ESP-IDF. Select source files to build in the project CMakeLists.txt file.

Reading CMake configuration...
[ESP-IDF] Ignoring components based on lib_ignore: arduinoota, bt, esp_i2s, esp_now, esp_rainmaker, esp_sr, insights, matter, micro-rtsp, mqtt, nimble-arduino, openthread, segger_rtt, wifiprov, zigbee
[nanopb] Installing Protocol Buffers dependencies
C:\Users\seanr\.platformio\penv\Scripts\python.exe: No module named pip
[nanopb] Installing gRPC dependencies
C:\Users\seanr\.platformio\penv\Scripts\python.exe: No module named pip
[nanopb] No generation needed.
Generating assembly for certificate bundle...
LDF: Library Dependency Finder -> https://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
[nanopb] Installing Protocol Buffers dependencies
C:\Users\seanr\.platformio\penv\Scripts\python.exe: No module named pip
[nanopb] Installing gRPC dependencies
C:\Users\seanr\.platformio\penv\Scripts\python.exe: No module named pip
[nanopb] No generation needed.
Found 98 compatible libraries
Scanning dependencies...
No dependencies
Building in release mode
Compiling .pio\build\thinknode-m2-raamses\.dummy\sketch.cpp.o
Compiling .pio\build\thinknode-m2-raamses\.dummy\arduino-lib-builder-gcc.c.o
Compiling .pio\build\thinknode-m2-raamses\.dummy\arduino-lib-builder-cpp.cpp.o
Compiling .pio\build\thinknode-m2-raamses\.dummy\arduino-lib-builder-as.S.o
Generating LD script .pio\build\thinknode-m2-raamses\esp-idf\esp_system\ld\memory.ld.in
Generating LD script .pio\build\thinknode-m2-raamses\esp-idf\esp_system\ld\sections.ld.in
Compiling .pio\build\thinknode-m2-raamses\app_trace\app_trace.c.o
Generating LD script .pio\build\thinknode-m2-raamses\memory.ld
Compiling .pio\build\thinknode-m2-raamses\app_trace\app_trace_util.c.o
Compiling .pio\build\thinknode-m2-raamses\app_trace\host_file_io.c.o
Compiling .pio\build\thinknode-m2-raamses\app_trace\port\port_uart.c.o
Compiling .pio\build\thinknode-m2-raamses\app_update\esp_ota_ops.c.o
Compiling .pio\build\thinknode-m2-raamses\app_update\esp_ota_app_desc.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_common.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_common_loader.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_clock_init.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_mem.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_random.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_efuse.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\flash_encrypt.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\secure_boot.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_random_esp32s3.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\bootloader_flash\src\bootloader_flash.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\app_trace\libapp_trace.a
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\bootloader_flash\src\flash_qio_mode.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\bootloader_flash\src\bootloader_flash_config_esp32s3.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_utility.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\flash_partitions.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\esp_image_format.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_sha.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\esp32s3\secure_boot_secure_features.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\controller\esp32c3\bt.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\app_update\libapp_update.a
Compiling .pio\build\thinknode-m2-raamses\bt\common\btc\core\btc_alarm.c.o
<command-line>: error: expected unqualified-id before numeric constant
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/variants/esp32s3/pins_arduino.h:25:22: note: in expansion of macro 'SDA'
   25 | static const uint8_t SDA = 8;
      |                      ^~~
<command-line>: error: expected unqualified-id before numeric constant
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/variants/esp32s3/pins_arduino.h:26:22: note: in expansion of macro 'SCL'
   26 | static const uint8_t SCL = 9;
      |                      ^~~
<command-line>: error: expected unqualified-id before numeric constant
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/variants/esp32s3/pins_arduino.h:28:22: note: in expansion of macro 'SS'
   28 | static const uint8_t SS = 10;
      |                      ^~
<command-line>: error: expected unqualified-id before numeric constant
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/variants/esp32s3/pins_arduino.h:29:22: note: in expansion of macro 'MOSI'
   29 | static const uint8_t MOSI = 11;
      |                      ^~~~
<command-line>: error: expected unqualified-id before numeric constant
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/variants/esp32s3/pins_arduino.h:30:22: note: in expansion of macro 'MISO'
   30 | static const uint8_t MISO = 13;
      |                      ^~~~
<command-line>: error: expected unqualified-id before numeric constant
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/variants/esp32s3/pins_arduino.h:31:22: note: in expansion of macro 'SCK'
   31 | static const uint8_t SCK = 12;
      |                      ^~~
Compiling .pio\build\thinknode-m2-raamses\bt\common\api\esp_blufi_api.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\bootloader_support\libbootloader_support.a
Compiling .pio\build\thinknode-m2-raamses\bt\common\hci_log\bt_hci_log.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\btc\core\btc_manage.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\btc\core\btc_task.c.o
*** [.pio\build\thinknode-m2-raamses\.dummy\sketch.cpp.o] Error 1
========================================================================================== [FAILED] Took 626.35 seconds ==========================================================================================

Environment           Status    Duration
--------------------  --------  ------------
thinknode-m2-raamses  FAILED    00:10:26.346
====================================================================================== 1 failed, 0 succeeded in 00:10:26.346 ======================================================================================