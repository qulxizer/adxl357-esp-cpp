#include "pl_adxl357.h"

//==============================================================================

const spi_host_device_t host = SPI2_HOST;
const int mosiPin = 5;
const int misoPin = 18;
const int sclkPin = 19;
const int sclkFrequency = 10000000;
const int csPin = 21;
const auto range = PL::Adxl357_Range::range2g;

//==============================================================================

extern "C" void app_main(void) {
  auto spi = std::make_shared<PL::Spi>(host, mosiPin, misoPin, sclkPin);
  PL::Adxl357 adxl357(spi, sclkFrequency, csPin);
  adxl357.Initialize();

  // Set ADXL357 range
  adxl357.SetRange(range);
  // Enable ADXL357 measurement
  adxl357.EnableMeasurement();

  while (1) {
    // Read and print the accelerations
    PL::Adxl357_Accelerations accelerations;
    adxl357.ReadAccelerations(accelerations);
    printf("Accelerations: X: %f g, Y: %f g, Z: %f g\n", accelerations.x, accelerations.y, accelerations.z);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}