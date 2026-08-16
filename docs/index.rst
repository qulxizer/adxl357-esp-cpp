Analog Devices ADXL357 Component
================================

.. |COMPONENT| replace:: adxl357

.. |ESP_IDF_VERSION| replace:: 5.3
   
.. |VERSION| replace:: 1.1.1

.. include:: ../../../installation.rst

.. include:: ../../../sdkconfig_common.rst


Functions
---------

Initialization
^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::Adxl357`, :cpp:func:`PL::Adxl357::Initialize`.

Range Configuration and Scale Factor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::ReadRange`, :cpp:func:`PL::Adxl357::SetRange`, :cpp:func:`PL::Adxl357::ReadAccelerationScaleFactor`.

Measurement Frequency Configuration
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::ReadOutputDataRate`, :cpp:func:`PL::Adxl357::SetOutputDataRate`.

Measurement Enable/Disable
^^^^^^^^^^^^^^^^^^^^^^^^^^
Use :cpp:func:`PL::Adxl357::EnableMeasurement`, :cpp:func:`PL::Adxl357::DisableMeasurement`,
:cpp:func:`PL::Adxl357::IsMeasurementEnabled`.

Single Measurement
^^^^^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::ReadAccelerations`/:cpp:func:`PL::Adxl357::ReadRawAccelerations`.

Waveform Measurement
^^^^^^^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::ReadNumberOfFifoSamples`, :cpp:func:`PL::Adxl357::ClearFifo`,
:cpp:func:`PL::Adxl357::ReadAccelerationsFromFifo`/:cpp:func:`PL::Adxl357::ReadRawAccelerationsFromFifo`.

Offset Configuration
^^^^^^^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::ReadOffsets`/:cpp:func:`PL::Adxl357::ReadRawOffsets`,
:cpp:func:`PL::Adxl357::SetOffsets`/:cpp:func:`PL::Adxl357::SetRawOffsets`.

Activity Detection
^^^^^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::ReadActivityDetectionAxes`, :cpp:func:`PL::Adxl357::SetActivityDetectionAxes`,
:cpp:func:`PL::Adxl357::ReadActivityDetectionThreshold`/:cpp:func:`PL::Adxl357::ReadRawActivityDetectionThreshold`,
:cpp:func:`PL::Adxl357::SetActivityDetectionThreshold`/:cpp:func:`PL::Adxl357::SetRawActivityDetectionThreshold`,
:cpp:func:`PL::Adxl357::ReadActivityDetectionCount`, :cpp:func:`PL::Adxl357::SetActivityDetectionCount`.

Temperature Measurement
^^^^^^^^^^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::EnableTemperature`, :cpp:func:`PL::Adxl357::DisableTemperature`,
:cpp:func:`PL::Adxl357::IsTemperatureEnabled`,
:cpp:func:`PL::Adxl357::ReadTemperature`/:cpp:func:`PL::Adxl357::ReadRawTemperature`.

Interrupt Configuration
^^^^^^^^^^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::ReadInterrupts`, :cpp:func:`PL::Adxl357::SetInterrupts`.

Device Information and Status
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::ReadDeviceInfo`, :cpp:func:`PL::Adxl357::ReadStatus`.

Self-test and Reset
^^^^^^^^^^^^^^^^^^^
:cpp:func:`PL::Adxl357::SelfTest`, :cpp:func:`PL::Adxl357::Reset`.

Other
^^^^^
:cpp:func:`PL::Adxl357::ReadHpfFrequency`, :cpp:func:`PL::Adxl357::SetHpfFrequency`,
:cpp:func:`PL::Adxl357::ReadFifoWatermark`, :cpp:func:`PL::Adxl357::SetFifoWatermark`,
:cpp:func:`PL::Adxl357::ReadSynchronization`, :cpp:func:`PL::Adxl357::SetSynchronization`,
:cpp:func:`PL::Adxl357::EnableExternalClock`, :cpp:func:`PL::Adxl357::DisableExternalClock`,
:cpp:func:`PL::Adxl357::IsExternalClockEnabled`
:cpp:func:`PL::Adxl357::ReadInterruptPolarity`, :cpp:func:`PL::Adxl357::SetInterruptPolarity`,
:cpp:func:`PL::Adxl357::ReadI2CSpeed`, :cpp:func:`PL::Adxl357::SetI2CSpeed`,
:cpp:func:`PL::Adxl357::EnableDataReady`, :cpp:func:`PL::Adxl357::DisableDataReady`,
:cpp:func:`PL::Adxl357::IsDataReadyEnabled`.

Thread safety
-------------

Class method thread safety is implemented by having the :cpp:class:`PL::Lockable` as a base class and creating the class object lock guard at the beginning of the methods.

:cpp:func:`PL::Adxl357::Initialize` and all transaction methods lock both
the :cpp:class:`PL::Adxl357` and the :cpp:class:`PL::Spi` objects for the duration of the method.

Examples
--------
| `Acceleration measurement <https://components.espressif.com/components/plasmapper/pl_adxl357/versions/1.1.1/examples/acceleration_measurement>`_
| `Acceleration waveform measurement <https://components.espressif.com/components/plasmapper/pl_adxl357/versions/1.1.1/examples/acceleration_waveform_measurement>`_
| `Activity detection <https://components.espressif.com/components/plasmapper/pl_adxl357/versions/1.1.1/examples/activity_detection>`_
| `Device info and self test <https://components.espressif.com/components/plasmapper/pl_adxl357/versions/1.1.1/examples/device_info_and_self_test>`_

API reference
-------------

.. toctree::
  
  api/adxl357
