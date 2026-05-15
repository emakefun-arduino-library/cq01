# Carbon Dioxide Concentration Sensor (CQ01) Arduino Library

A lightweight, header-only Arduino library for reading data from the CQ01 CO2 Sensor via I2C.

## Dependencies

- **EasyI2c**: Required for I2C register read operations.

## API Reference

1. **Constructor**:

    ```c++
    explicit constexpr Cq01(uint8_t i2c_address = kDefaultI2cAddress)
    ```

    Instantiates the sensor object. Uses the default I2C address `0x42` unless specified otherwise.

2. **Initialization**:

    ```c++
    void Init(TwoWire* wire)
    ```

    Binds the sensor to an I2C interface (e.g., &Wire). Must be called before reading data.

3. **Reading Data**:

    ```c++
    uint16_t co2_ppm() const
    ```

    Reads the CO2 concentration from the sensor's memory register.

    - **Returns**: CO2 value in **PPM** (Parts Per Million).

## Example

```c++
#include "cq01.h"

namespace {
em::Cq01 g_cq01(0x42);
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  g_cq01.Init(&Wire);
}

void loop() {
  Serial.print("CO2 ppm: ");
  Serial.println(g_cq01.co2_ppm());
  delay(1000);
}
```

## License

MIT License. See [LICENSE](LICENSE)
