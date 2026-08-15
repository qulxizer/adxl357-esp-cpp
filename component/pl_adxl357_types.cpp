#include "pl_adxl357_types.h"

//==============================================================================

namespace PL {

//==============================================================================

Adxl357_Status operator|(Adxl357_Status status1, Adxl357_Status status2) {
  return (Adxl357_Status)((uint8_t)status1 | (uint8_t)status2);
}

//==============================================================================

Adxl357_Status operator&(Adxl357_Status status1, Adxl357_Status status2) {
  return (Adxl357_Status)((uint8_t)status1 & (uint8_t)status2);
}

//==============================================================================

Adxl357_Axes operator|(Adxl357_Axes axis1, Adxl357_Axes axis2) {
  return (Adxl357_Axes)((uint8_t)axis1 | (uint8_t)axis2);
}

//==============================================================================

Adxl357_Axes operator&(Adxl357_Axes axis1, Adxl357_Axes axis2) {
  return (Adxl357_Axes)((uint8_t)axis1 & (uint8_t)axis2);
}

//==============================================================================

Adxl357_Interrupts operator|(Adxl357_Interrupts axis1,
                             Adxl357_Interrupts axis2) {
  return (Adxl357_Interrupts)((uint8_t)axis1 | (uint8_t)axis2);
}

//==============================================================================

Adxl357_Interrupts operator&(Adxl357_Interrupts axis1,
                             Adxl357_Interrupts axis2) {
  return (Adxl357_Interrupts)((uint8_t)axis1 & (uint8_t)axis2);
}

//==============================================================================

Adxl357_RawAccelerations::Adxl357_RawAccelerations() : x(0), y(0), z(0) {}

//==============================================================================

Adxl357_RawAccelerations::Adxl357_RawAccelerations(int32_t x, int32_t y,
                                                   int32_t z)
    : x(x), y(y), z(z) {}

//==============================================================================

Adxl357_Accelerations::Adxl357_Accelerations() : x(0), y(0), z(0) {}

//==============================================================================

Adxl357_Accelerations::Adxl357_Accelerations(float x, float y, float z)
    : x(x), y(y), z(z) {}

//==============================================================================

} // namespace PL
