#pragma once

#ifndef _CQ01_H_
#define _CQ01_H_

#include <Wire.h>

#include "easy_i2c.h"

/**
 * @class Cq01
 * @brief Represents the CQ01 CO2 sensor, providing methods to read CO2 concentration via I2C.
 */
class Cq01 {
 public:
  /**
   * @brief Default I2C address for the sensor.
   */
  static constexpr uint8_t kDefaultI2cAddress{0x42};

  /**
   * @brief Constructs a new Cq01 object.
   * @param[in] i2c_address The I2C address of the sensor (default is kDefaultI2cAddress).
   */
  explicit constexpr Cq01(const uint8_t i2c_address = kDefaultI2cAddress) : i2c_address_(i2c_address) {}

  /**
   * @brief Initializes the sensor with a specific TwoWire interface.
   * @param[in] wire Pointer to a TwoWire instance (e.g., &Wire).
   */
  void Init(TwoWire* wire) { wire_ = wire; }

  /**
   * @brief Reads the current CO2 concentration.
   * @return CO2 concentration in ppm (parts per million).
   */
  uint16_t co2_ppm() const { return easy_i2c::Read<uint16_t>(*wire_, i2c_address_, static_cast<uint8_t>(MemAddress::kCo2Ppm)); }

 private:
  Cq01() = delete;
  Cq01(const Cq01&) = delete;
  Cq01& operator=(const Cq01&) = delete;

  enum MemAddress : uint8_t {
    kCo2Ppm = 0x10,
  };

  const uint8_t i2c_address_;
  TwoWire* wire_ = nullptr;
};

#endif