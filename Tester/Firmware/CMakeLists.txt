list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/mcp4716_driver_module)
list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/pmw3360_driver_module)

cmake_minimum_required(VERSION 3.13.1)

set(BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(BOARD telescope_mirror_tester)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(telescope_mirror_tester)

target_sources(app PRIVATE src/main.c)
