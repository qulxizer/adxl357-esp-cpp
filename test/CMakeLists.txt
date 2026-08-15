cmake_minimum_required(VERSION 3.22)

set(EXTRA_COMPONENT_DIRS "../component/")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(pl_adxl357_test)
add_compile_options("-Wno-error=delete-non-abstract-non-virtual-dtor")
