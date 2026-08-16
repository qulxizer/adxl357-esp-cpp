#include "pl_adxl357.h"

//==============================================================================

const spi_host_device_t host = SPI2_HOST;
const int mosiPin = 11;
const int misoPin = 13;
const int sclkPin = 12;
const int sclkFrequency = 10000000;
const int csPin = 10;

//==============================================================================

extern "C" void app_main(void) {
  auto spi = std::make_shared<PL::Spi>(host, mosiPin, misoPin, sclkPin);
  PL::Adxl357 adxl357(spi, sclkFrequency, csPin);
  adxl357.Initialize();

  // Reset the ADXL357
  adxl357.Reset();

  // Read and print the device info
  PL::Adxl357_DeviceInfo deviceInfo;
  adxl357.ReadDeviceInfo(deviceInfo);
  printf("Vendor ID (should be 0xAD): 0x%02X\n", deviceInfo.vendorId);
  printf("Family ID (should be 0x1D): 0x%02X\n", deviceInfo.familyId);
  printf("Device ID (should be 0xED): 0x%02X\n", deviceInfo.deviceId);
  printf("Revision ID: 0x%02X\n\n", deviceInfo.revisionId);

  // Execute the self-test and print the results
  PL::Adxl357_Accelerations accelerations;
  adxl357.SelfTest(accelerations);
  printf("Self test (should be 0.5...3.0 g for Z-axis, typical 1.25 g): %f, "
         "%f, %f\n",
         accelerations.x, accelerations.y, accelerations.z);
}
