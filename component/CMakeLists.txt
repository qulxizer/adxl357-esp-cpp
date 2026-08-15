cmake_minimum_required(VERSION 3.22)

idf_component_register(SRCS "pl_adxl357_types.cpp" "pl_adxl357.cpp" INCLUDE_DIRS "include" REQUIRES "pl_spi")
