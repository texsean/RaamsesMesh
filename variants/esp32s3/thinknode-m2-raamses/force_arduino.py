# Force-include Arduino.h into every compilation unit.
# Arduino.h pulls in pins_arduino.h which defines SS/SCK/MOSI/MISO/SDA/SCL.
Import("env")

env.Append(CCFLAGS=[
    "-include",
    "Arduino.h",
])
