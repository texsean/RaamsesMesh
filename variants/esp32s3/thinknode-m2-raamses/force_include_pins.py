# Force-include pins_arduino.h into EVERY compilation unit.
# Framework SPI.cpp, Wire.cpp, SD.cpp don't include it themselves
# and fail with 'SS/SCK/MOSI/MISO/SDA/SCL not declared'.
# -include injects it at the preprocessor level globally.
Import("env")

env.Append(CCFLAGS=[
    "-include",
    "pins_arduino.h",
])
