#include "pl_adxl357.h"

//==============================================================================

const spi_host_device_t host = SPI2_HOST;
const int mosiPin = 5;
const int misoPin = 18;
const int sclkPin = 19;
const int sclkFrequency = 10000000;
const int csPin = 21;
const auto range = PL::Adxl357_Range::range10g;
auto activityAxes = PL::Adxl357_Axes::x | PL::Adxl357_Axes::y;
float activityThreshold = 1.5;
uint8_t activityCount = 5;

//==============================================================================

extern "C" void app_main(void) {
  auto spi = std::make_shared<PL::Spi>(host, mosiPin, misoPin, sclkPin);
  PL::Adxl357 adxl357(spi, sclkFrequency, csPin);
  adxl357.Initialize();

  // Set ADXL357 range
  adxl357.SetRange(range);
  // Set activity detection axes
  adxl357.SetActivityDetectionAxes(activityAxes);
  // Set activity detection threshold 
  adxl357.SetActivityDetectionThreshold(activityThreshold);
  // Set activity detection count
  adxl357.SetActivityDetectionCount(activityCount);
  // Enable ADXL357 measurement
  adxl357.EnableMeasurement();

  while (1) {
    PL::Adxl357_Status status;
    adxl357.ReadStatus(status);
    printf((bool)(status & PL::Adxl357_Status::activity) ? "Activity detected\n" : "No activity detected\n");

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}