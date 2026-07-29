# Inject SPI/I2C pin defines into the global construction environment.
# These reach ALL compilation units including framework SPI.cpp, Wire.cpp.
# Our pins_arduino.h uses #ifndef guards so no conflict with static const defs.
Import("env")

env.Append(CPPDEFINES=[
    ("SS", "10"),
    ("SCK", "12"),
    ("MOSI", "11"),
    ("MISO", "13"),
    ("SDA", "16"),
    ("SCL", "15"),
])
