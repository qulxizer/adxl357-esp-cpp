#include "pl_adxl357.h"

//==============================================================================

const spi_host_device_t host = SPI2_HOST;
const int mosiPin = 5;
const int misoPin = 18;
const int sclkPin = 19;
const int sclkFrequency = 10000000;
const int csPin = 21;
const auto range = PL::Adxl357_Range::range10g;
const auto outputDataRate = PL::Adxl357_OutputDataRate::odr4000;
const float timeStepMs = 1.0 / 4000.0 * 1000;
const int numberOfPoints = 10;

//==============================================================================

extern "C" void app_main(void) {
  auto spi = std::make_shared<PL::Spi>(host, mosiPin, misoPin, sclkPin);
  PL::Adxl357 adxl357(spi, sclkFrequency, csPin);
  adxl357.Initialize();

  // Set ADXL357 range
  adxl357.SetRange(range);
  // Set ADXL357 output data rate
  adxl357.SetOutputDataRate(outputDataRate);
  // Enable ADXL357 measurement
  adxl357.EnableMeasurement();

  while (1) {
    // Clear the FIFO
    printf("FIFO cleared\n");
    adxl357.ClearFifo();

    // Read the accelerations from the FIFO
    PL::Adxl357_Accelerations accelerations[numberOfPoints];
    for (int i = 0; i < numberOfPoints; i++)
      adxl357.ReadAccelerationsFromFifo(accelerations[i]);

    // Print the accelerations
    for (int i = 0; i < numberOfPoints; i++)
      printf("Time: %f ms, Accelerations: X: %f g, Y: %f g, Z: %f g\n", i * timeStepMs, accelerations[i].x, accelerations[i].y, accelerations[i].z);
    printf("\n");

    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}