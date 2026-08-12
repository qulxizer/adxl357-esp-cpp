# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]
### Added
- Timeout parameter to ReadRawAccelerationsFromFifo and ReadAccelerationsFromFifo.
- Tests for ReadStatus, ClearFifo, ReadAccelerations, ReadTemperature and SelfTest output values.

### Removed
- Redundant standby-mode acceleration read in SelfTest.

### Fixed
- SelfTest not restoring the acceleration range.
- SelfTest not clearing the FIFO.

## [1.0.0] - 2024-08-27
Initial release.