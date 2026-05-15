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