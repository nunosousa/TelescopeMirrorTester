# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

set(BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(BOARD telescope_mirror_tester)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(telescope_mirror_tester)

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/command_parser/command_parser.c)
target_sources(app PRIVATE src/motor_control/motor_control.c)
target_sources(app PRIVATE src/position_sensor/position_sensor.c)