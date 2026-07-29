PS C:\GitHub\RaamsesMesh\RaamsesMesh> pio run -e thinknode-m2-raamses -t upload --upload-port COM25
Processing thinknode-m2-raamses (board: ESP32-S3-WROOM-1-N4; platform:
https://github.com/meshtastic/pioarduino-platform-espressif32/archive/refs/heads/55.03.39.zip; framework: arduino)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Verbose mode can be enabled via `-v, --verbose` option
PROGNAME: firmware-thinknode-m2-raamses-2.8.0.9e43ab9
ESP32_FS_IMAGE_NAME: littlefs-thinknode-m2-raamses-2.8.0.9e43ab9
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
[ComponentManager] Protected BT library: bt
[ComponentManager] Protected BT library: nimble-arduino
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
Add: # meshtastic_hybridcompile_cache_key: memory_type=default spiram=none
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
Using meshtastic platformio-custom.py, firmware version 2.8.0.9e43ab9 on thinknode-m2-raamses
Using flags:
-DAPP_VERSION=2.8.0.9e43ab9
-DAPP_VERSION_SHORT=2.8.0
-DAPP_ENV=thinknode-m2-raamses
-DAPP_REPO=git@github.com:texsean/RaamsesMesh
-DBUILD_EPOCH=1785301200
-DUSERPREFS_RINGTONE_RTTTL=\"24:d=32,o=5,b=565:f6,p,f6,4p,p,f6,p,f6,2p,p,b6,p,b6,p,b6,p,b6,p,b,p,b,p,b,p,b,p,b,p,b,p,b,p,b,1p.,2p.,p\"
-DUSERPREFS_TZ_STRING=\"tzplaceholder                                         \"
Compiling .pio\build\thinknode-m2-raamses\.dummy\sketch.cpp.o
Compiling .pio\build\thinknode-m2-raamses\.dummy\arduino-lib-builder-gcc.c.o
Compiling .pio\build\thinknode-m2-raamses\.dummy\arduino-lib-builder-cpp.cpp.o
Compiling .pio\build\thinknode-m2-raamses\.dummy\arduino-lib-builder-as.S.o
Generating LD script .pio\build\thinknode-m2-raamses\esp-idf\esp_system\ld\memory.ld.in
Generating LD script .pio\build\thinknode-m2-raamses\esp-idf\esp_system\ld\sections.ld.in
Compiling .pio\build\thinknode-m2-raamses\app_trace\app_trace.c.o
Compiling .pio\build\thinknode-m2-raamses\app_trace\app_trace_util.c.o
Compiling .pio\build\thinknode-m2-raamses\app_trace\host_file_io.c.o
Compiling .pio\build\thinknode-m2-raamses\app_trace\port\port_uart.c.o
Compiling .pio\build\thinknode-m2-raamses\app_update\esp_ota_ops.c.o
Generating LD script .pio\build\thinknode-m2-raamses\memory.ld
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
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\bootloader_flash\src\flash_qio_mode.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\bootloader_flash\src\bootloader_flash_config_esp32s3.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_utility.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\flash_partitions.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\esp_image_format.c.o
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\bootloader_sha.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\app_trace\libapp_trace.a
Compiling .pio\build\thinknode-m2-raamses\bootloader_support\src\esp32s3\secure_boot_secure_features.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\controller\esp32c3\bt.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\btc\core\btc_alarm.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\app_update\libapp_update.a
Compiling .pio\build\thinknode-m2-raamses\bt\common\api\esp_blufi_api.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\hci_log\bt_hci_log.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\btc\core\btc_manage.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\btc\core\btc_task.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\btc\profile\esp\blufi\blufi_prf.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\bootloader_support\libbootloader_support.a
Compiling .pio\build\thinknode-m2-raamses\bt\common\btc\profile\esp\blufi\blufi_protocol.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\alarm.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\allocator.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\buffer.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\config.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\fixed_queue.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\pkt_queue.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\fixed_pkt_queue.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\future.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\hash_functions.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\hash_map.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\list.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\mutex.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\thread.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\osi.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\osi\semaphore.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\porting\mem\bt_osi_mem.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\ble_log\ble_log_spi_out.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\ble_log\ble_log_uhci_out.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\utils.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\sha256.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\ecc.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\ctr_prng.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\ctr_mode.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\aes_decrypt.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\aes_encrypt.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\ccm_mode.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\ecc_dsa.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\cmac_mode.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\ecc_dh.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\hmac_prng.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\ecc_platform_specific.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\hmac.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\src\cbc_mode.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\tinycrypt\port\esp_tinycrypt_port.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\transport\src\transport.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\util\src\addr.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\gatt\src\ble_svc_gatt.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\tps\src\ble_svc_tps.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\ias\src\ble_svc_ias.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\ipss\src\ble_svc_ipss.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\ans\src\ble_svc_ans.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\hr\src\ble_svc_hr.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\htp\src\ble_svc_htp.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\gap\src\ble_svc_gap.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\bas\src\ble_svc_bas.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\dis\src\ble_svc_dis.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\lls\src\ble_svc_lls.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\prox\src\ble_svc_prox.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\cts\src\ble_svc_cts.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\hid\src\ble_svc_hid.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\sps\src\ble_svc_sps.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\cte\src\ble_svc_cte.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\services\ras\src\ble_svc_ras.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_cs.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_conn.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_store_util.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_sm.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_shutdown.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_l2cap_sig_cmd.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_hci_cmd.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_id.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_att_svr.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_gatts_lcl.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_ibeacon.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_atomic.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_sm_alg.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_stop.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_hci_evt.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_mqueue.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_periodic_sync.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_att.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_ead.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_aes_ccm.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_gattc.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_store.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_sm_lgcy.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_cfg.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_att_clt.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_l2cap_coc.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_mbuf.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_att_cmd.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_log.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_eddystone.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_startup.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_l2cap_sig.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_gap.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_sm_cmd.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_uuid.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_pvcy.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_flow.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_l2cap.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_sm_sc.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_misc.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_gatts.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_adv.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_hci.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_hci_util.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_hs_resolv.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\store\ram\src\ble_store_ram.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\store\config\src\ble_store_config.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\store\config\src\ble_store_nvs.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_gattc_cache.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_gattc_cache_conn.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\host\src\ble_eatt.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\porting\nimble\src\nimble_port.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\porting\npl\freertos\src\nimble_port_freertos.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\port\src\nvs_port.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\porting\nimble\src\endian.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\porting\nimble\src\os_mempool.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\porting\nimble\src\mem.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\porting\nimble\src\os_mbuf.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\porting\nimble\src\os_msys_init.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\porting\npl\freertos\src\npl_os_freertos.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\esp-hci\src\esp_nimble_hci.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\host\nimble\nimble\nimble\transport\esp_ipc_legacy\src\hci_esp_ipc_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\bt\common\btc\profile\esp\blufi\nimble_host\esp_blufi.c.o
Compiling .pio\build\thinknode-m2-raamses\cmock\CMock\src\cmock.c.o
Compiling .pio\build\thinknode-m2-raamses\console\commands.c.o
Compiling .pio\build\thinknode-m2-raamses\console\esp_console_common.c.o
Compiling .pio\build\thinknode-m2-raamses\console\esp_console_repl_internal.c.o
Compiling .pio\build\thinknode-m2-raamses\console\split_argv.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\cmock\libcmock.a
Compiling .pio\build\thinknode-m2-raamses\console\linenoise\linenoise.c.o
Compiling .pio\build\thinknode-m2-raamses\console\esp_console_repl_chip.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_cmd.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\bt\libbt.a
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_date.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_dbl.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_dstr.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_end.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_file.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_hashtable.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_int.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_lit.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_rem.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_rex.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_str.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\arg_utils.c.o
Compiling .pio\build\thinknode-m2-raamses\console\argtable3\argtable3.c.o
Compiling .pio\build\thinknode-m2-raamses\cxx\cxx_exception_stubs.cpp.o
Compiling .pio\build\thinknode-m2-raamses\cxx\cxx_guards.cpp.o
Compiling .pio\build\thinknode-m2-raamses\cxx\cxx_init.cpp.o
Compiling .pio\build\thinknode-m2-raamses\driver\deprecated\adc_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\deprecated\adc_dma_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\deprecated\timer_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\i2c\i2c.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\deprecated\i2s_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\deprecated\mcpwm_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\deprecated\pcnt_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\deprecated\rmt_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\deprecated\sigma_delta_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\deprecated\rtc_temperature_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\touch_sensor\touch_sensor_common.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\touch_sensor\esp32s3\touch_sensor.c.o
Compiling .pio\build\thinknode-m2-raamses\driver\twai\twai.c.o
Compiling .pio\build\thinknode-m2-raamses\efuse\esp32s3\esp_efuse_table.c.o
Compiling .pio\build\thinknode-m2-raamses\efuse\esp32s3\esp_efuse_fields.c.o
Compiling .pio\build\thinknode-m2-raamses\efuse\esp32s3\esp_efuse_rtc_calib.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\console\libconsole.a
Compiling .pio\build\thinknode-m2-raamses\efuse\esp32s3\esp_efuse_utility.c.o
Compiling .pio\build\thinknode-m2-raamses\efuse\src\esp_efuse_api.c.o
Compiling .pio\build\thinknode-m2-raamses\efuse\src\esp_efuse_fields.c.o
Compiling .pio\build\thinknode-m2-raamses\efuse\src\esp_efuse_utility.c.o
Compiling .pio\build\thinknode-m2-raamses\efuse\src\efuse_controller\keys\with_key_purposes\esp_efuse_api_key.c.o
Compiling .pio\build\thinknode-m2-raamses\efuse\src\esp_efuse_startup.c.o
Compiling .pio\build\thinknode-m2-raamses\esp-tls\esp_tls.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\cxx\libcxx.a
Compiling .pio\build\thinknode-m2-raamses\esp-tls\esp-tls-crypto\esp_tls_crypto.c.o
Compiling .pio\build\thinknode-m2-raamses\esp-tls\esp_tls_error_capture.c.o
Compiling .pio\build\thinknode-m2-raamses\esp-tls\esp_tls_platform_port.c.o
Compiling .pio\build\thinknode-m2-raamses\esp-tls\esp_tls_mbedtls.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_adc\adc_oneshot.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_adc\adc_common.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\efuse\libefuse.a
Compiling .pio\build\thinknode-m2-raamses\esp_adc\adc_cali.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_adc\adc_cali_curve_fitting.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_adc\deprecated\esp_adc_cal_common_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_adc\adc_continuous.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_adc\adc_monitor.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_adc\gdma\adc_dma.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_adc\adc_filter.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_adc\esp32s3\curve_fitting_coefficients.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_adc\deprecated\esp32s3\esp_adc_cal_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_app_format\esp_app_desc.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_bootloader_format\esp_bootloader_desc.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_coex\src\coexist.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_coex\src\lib_printf.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_coex\esp32s3\esp_coex_adapter.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_coex\src\coexist_debug_diagram.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_coex\src\coexist_debug.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_common\src\esp_err_to_name.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_bootloader_format\libesp_bootloader_format.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\driver\libdriver.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_cam\esp_cam_ctlr.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_app_format\libesp_app_format.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_cam\dvp_share_ctrl.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_cam\dvp\src\esp_cam_ctlr_dvp_gdma.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_adc\libesp_adc.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_coex\libesp_coex.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_cam\dvp\src\esp_cam_ctlr_dvp_cam.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp-tls\libesp-tls.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_gpio\src\gpio.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_gpio\src\gpio_glitch_filter_ops.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_gpio\src\rtc_io.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_gpio\src\dedic_gpio.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_gpio\src\gpio_pin_glitch_filter.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_gptimer\src\gptimer.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_gptimer\src\gptimer_common.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_i2c\i2c_master.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_common\libesp_common.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_i2c\i2c_common.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_i2c\i2c_slave.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_i2s\i2s_common.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_cam\libesp_driver_cam.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_i2s\i2s_std.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_i2s\i2s_pdm.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_i2s\i2s_tdm.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_i2s\i2s_platform.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_ledc\src\ledc.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_mcpwm\src\mcpwm_cap.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_mcpwm\src\mcpwm_cmpr.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_mcpwm\src\mcpwm_com.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_mcpwm\src\mcpwm_fault.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_mcpwm\src\mcpwm_gen.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_mcpwm\src\mcpwm_oper.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_mcpwm\src\mcpwm_sync.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_mcpwm\src\mcpwm_timer.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_pcnt\src\pulse_cnt.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_rmt\src\rmt_common.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_gptimer\libesp_driver_gptimer.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_gpio\libesp_driver_gpio.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_rmt\src\rmt_encoder.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_rmt\src\rmt_encoder_bytes.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_rmt\src\rmt_encoder_copy.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_rmt\src\rmt_encoder_simple.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_rmt\src\rmt_rx.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_rmt\src\rmt_tx.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_sdm\src\sdm.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_sdmmc\src\sdmmc_transaction.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_sdmmc\src\sdmmc_host.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_sdspi\src\sdspi_crc.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_sdspi\src\sdspi_host.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_i2c\libesp_driver_i2c.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_i2s\libesp_driver_i2s.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_sdspi\src\sdspi_transaction.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_spi\src\gpspi\spi_common.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_mcpwm\libesp_driver_mcpwm.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_spi\src\gpspi\spi_master.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_spi\src\gpspi\spi_slave.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_spi\src\gpspi\spi_slave_hd.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_touch_sens\common\touch_sens_common.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_pcnt\libesp_driver_pcnt.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_touch_sens\hw_ver2\touch_version_specific.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_ledc\libesp_driver_ledc.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_tsens\src\temperature_sensor.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_twai\esp_twai.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_sdm\libesp_driver_sdm.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_twai\esp_twai_onchip.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_uart\src\uart.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_uart\src\uart_wakeup.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_uart\src\uhci.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_uart\src\uart_vfs.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_usb_serial_jtag\src\usb_serial_jtag.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_rmt\libesp_driver_rmt.a
Compiling .pio\build\thinknode-m2-raamses\esp_driver_usb_serial_jtag\src\usb_serial_jtag_connection_monitor.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_driver_usb_serial_jtag\src\usb_serial_jtag_vfs.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_eth\src\esp_eth.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_touch_sens\libesp_driver_touch_sens.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_tsens\libesp_driver_tsens.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_sdmmc\libesp_driver_sdmmc.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_sdspi\libesp_driver_sdspi.a
Compiling .pio\build\thinknode-m2-raamses\esp_eth\src\phy\esp_eth_phy_802_3.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_twai\libesp_driver_twai.a
Compiling .pio\build\thinknode-m2-raamses\esp_eth\src\esp_eth_netif_glue.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_usb_serial_jtag\libesp_driver_usb_serial_jtag.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_spi\libesp_driver_spi.a
Compiling .pio\build\thinknode-m2-raamses\esp_eth\src\spi\dm9051\esp_eth_mac_dm9051.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_eth\src\spi\dm9051\esp_eth_phy_dm9051.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_eth\src\spi\w5500\esp_eth_mac_w5500.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_eth\src\spi\w5500\esp_eth_phy_w5500.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_eth\src\spi\ksz8851snl\esp_eth_mac_ksz8851snl.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_eth\src\spi\ksz8851snl\esp_eth_phy_ksz8851snl.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_event\default_event_loop.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_event\esp_event.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_event\esp_event_private.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_driver_uart\libesp_driver_uart.a
Compiling .pio\build\thinknode-m2-raamses\esp_gdbstub\src\gdbstub.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_gdbstub\src\gdbstub_transport.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_gdbstub\src\packet.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_gdbstub\src\port\xtensa\gdbstub_xtensa.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_gdbstub\src\port\xtensa\gdbstub-entry.S.o
Compiling .pio\build\thinknode-m2-raamses\esp_gdbstub\src\port\xtensa\xt_debugexception.S.o
Compiling .pio\build\thinknode-m2-raamses\esp_hid\src\esp_hidd.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hid\src\esp_hidh.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_eth\libesp_eth.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_gdbstub\libesp_gdbstub.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_event\libesp_event.a
Compiling .pio\build\thinknode-m2-raamses\esp_hid\src\esp_hid_common.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hid\src\nimble_hidd.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hid\src\nimble_hidh.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_client\esp_http_client.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_client\lib\http_auth.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_client\lib\http_header.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_client\lib\http_utils.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_server\src\httpd_main.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_server\src\httpd_parse.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_server\src\httpd_sess.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_server\src\httpd_txrx.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_server\src\httpd_uri.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_server\src\httpd_ws.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_http_server\src\util\ctrl_sock.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_https_ota\src\esp_https_ota.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_https_server\src\https_server.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\cpu.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\esp_cpu_intr.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\esp_memory_utils.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\cpu_region_protect.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\esp_clk.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\clk_ctrl_os.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\hw_random.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\intr_alloc.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\mac_addr.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\periph_ctrl.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_hid\libesp_hid.a
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\revision.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\rtc_module.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\regi2c_ctrl.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\esp_gpio_reserve.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\sar_periph_ctrl_common.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\io_mux.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\esp_clk_tree.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\dma\esp_dma_utils.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\dma\gdma_link.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\spi_bus_lock.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\clk_utils.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp_clk_tree_common.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\spi_share_hw_ctrl.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\adc_share_hw_ctrl.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_http_server\libesp_http_server.a
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\sleep_modem.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\sleep_modes.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_https_ota\libesp_https_ota.a
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\sleep_console.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_https_server\libesp_https_server.a
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\sleep_mspi.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\sleep_usb.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\sleep_gpio.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\sleep_event.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_http_client\libesp_http_client.a
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\dma\gdma.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\deprecated\gdma_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\dma\esp_async_memcpy.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\dma\async_memcpy_gdma.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\systimer.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\mspi_timing_tuning\mspi_timing_tuning.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\sleep_wake_stub.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\esp_clock_output.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\power_supply\brownout.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\rtc_clk.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\rtc_clk_init.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\rtc_init.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\rtc_sleep.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\rtc_time.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\chip_info.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\port\esp32s3\sar_periph_ctrl.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\mspi_timing_tuning\port\esp32s3\mspi_timing_config.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\mspi_timing_tuning\port\esp32s3\mspi_timing_by_mspi_delay.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_hw_support\lowpower\port\esp32s3\sleep_cpu.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\src\esp_lcd_common.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\src\esp_lcd_panel_io.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\src\esp_lcd_panel_nt35510.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_hw_support\libesp_hw_support.a
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\src\esp_lcd_panel_ssd1306.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\src\esp_lcd_panel_st7789.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\src\esp_lcd_panel_ops.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\i2c\esp_lcd_panel_io_i2c_v1.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\i2c\esp_lcd_panel_io_i2c_v2.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\spi\esp_lcd_panel_io_spi.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\i80\esp_lcd_panel_io_i80.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_lcd\rgb\esp_lcd_panel_rgb.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_local_ctrl\src\esp_local_ctrl.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_local_ctrl\src\esp_local_ctrl_handler.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_local_ctrl\proto-c\esp_local_ctrl.pb-c.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_local_ctrl\src\esp_local_ctrl_transport_ble.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_local_ctrl\src\esp_local_ctrl_transport_httpd.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_mm\esp_mmu_map.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_mm\port\esp32s3\ext_mem_layout.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_mm\esp_cache_msync.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_mm\esp_cache_utils.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_mm\heap_align_hw.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_netif\esp_netif_handlers.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_netif\esp_netif_objects.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_netif\esp_netif_defaults.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_netif\lwip\esp_netif_lwip.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_lcd\libesp_lcd.a
Compiling .pio\build\thinknode-m2-raamses\esp_netif\lwip\esp_netif_sntp.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_netif\lwip\esp_netif_lwip_defaults.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_netif\lwip\netif\wlanif.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_netif\lwip\netif\ethernetif.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_netif\lwip\netif\esp_pbuf_ref.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_partition\partition.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_partition\partition_target.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_phy\src\phy_override.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_phy\src\lib_printf.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_phy\src\phy_common.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_phy\src\phy_init.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_phy\esp32s3\phy_init_data.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_phy\src\btbb_init.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_pm\pm_locks.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_pm\pm_trace.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_pm\pm_impl.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_local_ctrl\libesp_local_ctrl.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_mm\libesp_mm.a
Compiling .pio\build\thinknode-m2-raamses\esp_psram\system_layer\esp_psram_mspi.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_ringbuf\ringbuf.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_sys.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_print.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_crc.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_uart.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_spiflash.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_efuse.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_gpio.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_longjmp.S.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_systimer.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_wdt.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_cache_esp32s2_esp32s3.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_partition\libesp_partition.a
Compiling .pio\build\thinknode-m2-raamses\esp_rom\patches\esp_rom_cache_writeback_esp32s3.S.o
Compiling .pio\build\thinknode-m2-raamses\esp_security\src\init.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_security\src\esp_hmac.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_security\src\esp_ds.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_security\src\esp_crypto_lock.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_security\src\esp_crypto_periph_clk.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\esp_err.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\crosscore_int.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_phy\libesp_phy.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_psram\libesp_psram.a
Compiling .pio\build\thinknode-m2-raamses\esp_system\esp_ipc.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\esp_system_console.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\freertos_hooks.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_pm\libesp_pm.a
Compiling .pio\build\thinknode-m2-raamses\esp_system\int_wdt.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\panic.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\esp_system.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\startup.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\startup_funcs.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_netif\libesp_netif.a
Compiling .pio\build\thinknode-m2-raamses\esp_system\system_time.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\stack_check.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\ubsan.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\xt_wdt.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_ringbuf\libesp_ringbuf.a
Compiling .pio\build\thinknode-m2-raamses\esp_system\task_wdt\task_wdt.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_rom\libesp_rom.a
Compiling .pio\build\thinknode-m2-raamses\esp_system\task_wdt\task_wdt_impl_timergroup.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\cpu_start.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\panic_handler.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\esp_system_chip.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\image_process.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\esp_ipc_isr.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_security\libesp_security.a
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\esp_ipc_isr_port.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\esp_ipc_isr_handler.S.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\esp_ipc_isr_routines.S.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\panic_arch.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\panic_handler_asm.S.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\expression_with_stack.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\expression_with_stack_asm.S.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\debug_helpers.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\debug_helpers_asm.S.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\debug_stubs.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\arch\xtensa\trax.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\soc\esp32s3\highint_hdl.S.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\soc\esp32s3\clk.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\soc\esp32s3\reset_reason.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\soc\esp32s3\system_internal.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\soc\esp32s3\cache_err_int.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_system\port\soc\esp32s3\apb_backup_dma.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_timer\src\esp_timer.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_timer\src\esp_timer_init.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_timer\src\ets_timer_legacy.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_timer\src\system_time.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_timer\src\esp_timer_impl_common.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_timer\src\esp_timer_impl_systimer.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_vfs_console\vfs_console.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_wifi\src\lib_printf.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_wifi\src\mesh_event.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_wifi\src\smartconfig.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_wifi\src\wifi_init.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_wifi\src\wifi_default.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_wifi\src\wifi_netif.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_wifi\src\wifi_default_ap.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_wifi\esp32s3\esp_adapter.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_wifi\regulatory\esp_wifi_regulatory.c.o
Compiling .pio\build\thinknode-m2-raamses\esp_wifi\src\smartconfig_ack.c.o
Compiling .pio\build\thinknode-m2-raamses\espcoredump\src\core_dump_init.c.o
Compiling .pio\build\thinknode-m2-raamses\espcoredump\src\core_dump_common.c.o
Compiling .pio\build\thinknode-m2-raamses\espcoredump\src\core_dump_flash.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_system\libesp_system.a
Compiling .pio\build\thinknode-m2-raamses\espcoredump\src\core_dump_uart.c.o
Compiling .pio\build\thinknode-m2-raamses\espcoredump\src\core_dump_elf.c.o
Compiling .pio\build\thinknode-m2-raamses\espcoredump\src\core_dump_binary.c.o
Compiling .pio\build\thinknode-m2-raamses\espcoredump\src\core_dump_sha.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_timer\libesp_timer.a
Compiling .pio\build\thinknode-m2-raamses\espcoredump\src\core_dump_crc.c.o
Compiling .pio\build\thinknode-m2-raamses\espcoredump\src\port\xtensa\core_dump_port.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_vfs_console\libesp_vfs_console.a
Compiling .pio\build\thinknode-m2-raamses\espcoredump\src\port\xtensa\core_dump_stack_switch.S.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cborencoder_close_container_checked.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cborencoder.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cborencoder_float.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cborerrorstrings.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cborparser_dup_string.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cborparser.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cborparser_float.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cborpretty_stdio.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cborpretty.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cbortojson.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\cborvalidation.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__cbor\tinycbor\src\open_memstream.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__fb_gfx\fb_gfx.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_responder.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_receive.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\esp_wifi\libesp_wifi.a
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_utils.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_debug.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_browser.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_send.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_netif.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_querier.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_pcb.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_service.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_mem_caps.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\espcoredump\libespcoredump.a
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__mdns\mdns_networking_lwip.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\src\network_config.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\src\network_scan.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\espressif__fb_gfx\libespressif__fb_gfx.a
Archiving .pio\build\thinknode-m2-raamses\esp-idf\espressif__cbor\libespressif__cbor.a
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\src\network_ctrl.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\src\manager.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\src\handlers.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\src\scheme_console.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\proto-c\network_config.pb-c.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\proto-c\network_scan.pb-c.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\proto-c\network_ctrl.pb-c.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\proto-c\network_constants.pb-c.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\src\scheme_softap.c.o
Compiling .pio\build\thinknode-m2-raamses\managed_components\espressif__network_provisioning\src\scheme_ble.c.o
Compiling .pio\build\thinknode-m2-raamses\fatfs\diskio\diskio.c.o
Compiling .pio\build\thinknode-m2-raamses\fatfs\diskio\diskio_rawflash.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\espressif__mdns\libespressif__mdns.a
Compiling .pio\build\thinknode-m2-raamses\fatfs\diskio\diskio_wl.c.o
Compiling .pio\build\thinknode-m2-raamses\fatfs\src\ff.c.o
Compiling .pio\build\thinknode-m2-raamses\fatfs\src\ffunicode.c.o
Compiling .pio\build\thinknode-m2-raamses\fatfs\port\freertos\ffsystem.c.o
Compiling .pio\build\thinknode-m2-raamses\fatfs\diskio\diskio_sdmmc.c.o
Compiling .pio\build\thinknode-m2-raamses\fatfs\vfs\vfs_fat.c.o
Compiling .pio\build\thinknode-m2-raamses\fatfs\vfs\vfs_fat_sdmmc.c.o
Compiling .pio\build\thinknode-m2-raamses\fatfs\vfs\vfs_fat_spiflash.c.o
Compiling .pio\build\thinknode-m2-raamses\base64.cpp.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\espressif__network_provisioning\libespressif__network_provisioning.a
Compiling .pio\build\thinknode-m2-raamses\cbuf.cpp.o
Compiling .pio\build\thinknode-m2-raamses\ColorFormat.c.o
Compiling .pio\build\thinknode-m2-raamses\chip-debug-report.cpp.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-adc.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-bt.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-cpu.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-dac.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-gpio.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-hosted.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-i2c.c.o
Archiving .pio\build\thinknode-m2-raamses\esp-idf\fatfs\libfatfs.a
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-i2c-ng.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-i2c-slave.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-ledc.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-log-wrapper.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-matrix.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-misc.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-periman.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-ldo.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-psram.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-rgb-led.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-sigmadelta.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-spi.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-time.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-timer.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-tinyusb.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-touch.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-touch-ng.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-uart.c.o
Compiling .pio\build\thinknode-m2-raamses\esp32-hal-rmt.c.o
Compiling .pio\build\thinknode-m2-raamses\Esp.cpp.o
Compiling .pio\build\thinknode-m2-raamses\freertos_stats.cpp.o
Compiling .pio\build\thinknode-m2-raamses\FunctionalInterrupt.cpp.o
Compiling .pio\build\thinknode-m2-raamses\HardwareSerial.cpp.o
Compiling .pio\build\thinknode-m2-raamses\HashBuilder.cpp.o
Compiling .pio\build\thinknode-m2-raamses\HEXBuilder.cpp.o
Compiling .pio\build\thinknode-m2-raamses\idf_openthread_mpool_wrapper.c.o
Compiling .pio\build\thinknode-m2-raamses\IPAddress.cpp.o
Compiling .pio\build\thinknode-m2-raamses\cdecode.c.o
Compiling .pio\build\thinknode-m2-raamses\cencode.c.o
Compiling .pio\build\thinknode-m2-raamses\MacAddress.cpp.o
Compiling .pio\build\thinknode-m2-raamses\main.cpp.o
Compiling .pio\build\thinknode-m2-raamses\MD5Builder.cpp.o
Compiling .pio\build\thinknode-m2-raamses\Print.cpp.o
Compiling .pio\build\thinknode-m2-raamses\stdlib_noniso.c.o
Compiling .pio\build\thinknode-m2-raamses\Stream.cpp.o
Compiling .pio\build\thinknode-m2-raamses\StreamString.cpp.o
Compiling .pio\build\thinknode-m2-raamses\StringUtils.cpp.o
Compiling .pio\build\thinknode-m2-raamses\Tone.cpp.o
Compiling .pio\build\thinknode-m2-raamses\HWCDC.cpp.o
Compiling .pio\build\thinknode-m2-raamses\USB.cpp.o
Compiling .pio\build\thinknode-m2-raamses\USBCDC.cpp.o
Compiling .pio\build\thinknode-m2-raamses\USBMSC.cpp.o
Compiling .pio\build\thinknode-m2-raamses\FirmwareMSC.cpp.o
Compiling .pio\build\thinknode-m2-raamses\firmware_msc_fat.c.o
Compiling .pio\build\thinknode-m2-raamses\wiring_pulse.c.o
Compiling .pio\build\thinknode-m2-raamses\wiring_shift.c.o
Compiling .pio\build\thinknode-m2-raamses\WMath.cpp.o
Compiling .pio\build\thinknode-m2-raamses\WString.cpp.o
Compiling .pio\build\thinknode-m2-raamses\AsyncUDP.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLE2901.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLE2902.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLE2904.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEAddress.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEAdvertisedDevice.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEAdvertising.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEBeacon.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLECharacteristic.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLECharacteristicMap.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEClient.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEDescriptor.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEDescriptorMap.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEDevice.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEEddystoneTLM.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEEddystoneURL.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEExceptions.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEHIDDevice.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLERemoteCharacteristic.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLERemoteDescriptor.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLERemoteService.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEScan.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLESecurity.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEServer.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEService.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEServiceMap.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEUtils.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEUUID.cpp.o
Compiling .pio\build\thinknode-m2-raamses\BLEValue.cpp.o
Compiling .pio\build\thinknode-m2-raamses\FreeRTOS.cpp.o
Compiling .pio\build\thinknode-m2-raamses\GeneralUtils.cpp.o
Compiling .pio\build\thinknode-m2-raamses\EEPROM.cpp.o
Compiling .pio\build\thinknode-m2-raamses\ESPmDNS.cpp.o
Compiling .pio\build\thinknode-m2-raamses\FS.cpp.o
Compiling .pio\build\thinknode-m2-raamses\vfs_api.cpp.o
Compiling .pio\build\thinknode-m2-raamses\SHA1Builder.cpp.o
Compiling .pio\build\thinknode-m2-raamses\SHA2Builder.cpp.o
Compiling .pio\build\thinknode-m2-raamses\SHA3Builder.cpp.o
Compiling .pio\build\thinknode-m2-raamses\PBKDF2_HMACBuilder.cpp.o
Compiling .pio\build\thinknode-m2-raamses\LittleFS.cpp.o
Compiling .pio\build\thinknode-m2-raamses\NetworkInterface.cpp.o
Compiling .pio\build\thinknode-m2-raamses\NetworkEvents.cpp.o
Compiling .pio\build\thinknode-m2-raamses\NetworkManager.cpp.o
Compiling .pio\build\thinknode-m2-raamses\NetworkClient.cpp.o
Compiling .pio\build\thinknode-m2-raamses\NetworkServer.cpp.o
Compiling .pio\build\thinknode-m2-raamses\NetworkUdp.cpp.o
Compiling .pio\build\thinknode-m2-raamses\Preferences.cpp.o
Compiling .pio\build\thinknode-m2-raamses\SD_MMC.cpp.o
Compiling .pio\build\thinknode-m2-raamses\SD.cpp.o
Compiling .pio\build\thinknode-m2-raamses\sd_diskio.cpp.o
Compiling .pio\build\thinknode-m2-raamses\sd_diskio_crc.c.o
Compiling .pio\build\thinknode-m2-raamses\SPIFFS.cpp.o
Compiling .pio\build\thinknode-m2-raamses\SPI.cpp.o
Compiling .pio\build\thinknode-m2-raamses\Ticker.cpp.o
Compiling .pio\build\thinknode-m2-raamses\Updater.cpp.o
Compiling .pio\build\thinknode-m2-raamses\HttpsOTAUpdate.cpp.o
Compiling .pio\build\thinknode-m2-raamses\Updater_Signing.cpp.o
Compiling .pio\build\thinknode-m2-raamses\ssl_client.cpp.o
Compiling .pio\build\thinknode-m2-raamses\NetworkClientSecure.cpp.o
Compiling .pio\build\thinknode-m2-raamses\WiFiAP.cpp.o
Compiling .pio\build\thinknode-m2-raamses\WiFi.cpp.o
Compiling .pio\build\thinknode-m2-raamses\WiFiGeneric.cpp.o
Compiling .pio\build\thinknode-m2-raamses\WiFiMulti.cpp.o
Compiling .pio\build\thinknode-m2-raamses\WiFiScan.cpp.o
Compiling .pio\build\thinknode-m2-raamses\WiFiSTA.cpp.o
Compiling .pio\build\thinknode-m2-raamses\STA.cpp.o
Compiling .pio\build\thinknode-m2-raamses\AP.cpp.o
Compiling .pio\build\thinknode-m2-raamses\Wire.cpp.o
Compiling .pio\build\thinknode-m2-raamses\freertos\heap_idf.c.o
Compiling .pio\build\thinknode-m2-raamses\freertos\app_startup.c.o
Compiling .pio\build\thinknode-m2-raamses\freertos\port_common.c.o
Compiling .pio\build\thinknode-m2-raamses\freertos\port_systick.c.o
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
Compiling .pio\build\thinknode-m2-raamses\freertos\FreeRTOS-Kernel\list.c.o
*** [.pio\build\thinknode-m2-raamses\SPI.cpp.o] Error 1
In file included from C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SD/src/SD.cpp:19:
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/SD/src/SD.h:31:21: error: 'SS' was not declared in this scope; did you mean 'FS'?
   31 |     uint8_t ssPin = ←[01;31m←[KSS←[m←[K, SPIClass &spi = SPI, uint32_t frequency = 4000000, const char *mountpoint = "/sd", uint8_t max_files = 5, bool format_if_empty = false
      |                     ^~
      |                     FS
*** [.pio\build\thinknode-m2-raamses\SD.cpp.o] Error 1
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.cpp: In member function 'bool TwoWire::initPins(int, int)':
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.cpp:73:18: error: 'SDA' was not declared in this scope
   73 |         sdaPin = SDA;  //use Default Pin
      |                  ^~~
C:/Users/seanr/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src/Wire.cpp:94:18: error: 'SCL' was not declared in this scope
   94 |         sclPin = SCL;  // use Default pin
      |                  ^~~
*** [.pio\build\thinknode-m2-raamses\Wire.cpp.o] Error 1
========================================================================================== [FAILED] Took 107.75 seconds ==========================================================================================

Environment           Status    Duration
--------------------  --------  ------------
thinknode-m2-raamses  FAILED    00:01:47.746
====================================================================================== 1 failed, 0 succeeded in 00:01:47.746 ======================================================================================