# Inject SPI/I2C pin defines into the GLOBAL construction environment
# so they reach framework libraries (SPI.cpp, Wire.cpp) which don't
# inherit from projenv and therefore don't see build_flags.
Import("env")

env.Append(CPPDEFINES=[
    ("MOSI", "11"),
    ("MISO", "13"),
    ("SCK", "12"),
    ("SS", "10"),
    ("SDA", "16"),
    ("SCL", "15"),
])
