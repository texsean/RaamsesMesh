# Prepend our variant directory to the include path so our
# pins_arduino.h is found BEFORE the framework's default.
# Without this, SPI.cpp and Wire.cpp resolve #include "pins_arduino.h"
# to the framework's generic ESP32-S3 default (pin 8/9/10/11/12/13)
# instead of our variant (LORA_CS/LORA_SCK etc.).
Import("env")

variant_dir = env.subst("$PROJECT_DIR") + "/variants/esp32s3/thinknode-m2-raamses"
env.Prepend(CPPPATH=[variant_dir])
