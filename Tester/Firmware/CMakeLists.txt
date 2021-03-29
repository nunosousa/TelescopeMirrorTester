# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

set(BOARD BOARD_TELESCOPE_MIRROR_TESTER)
#set(BOARD_ROOT ~/Git/TelescopeMirrorTester/Tester/Firmware/boards/arm/telescope_mirror_tester)
#set(ZEPHYR_MODULES <VALUE>)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(telescope_mirror_tester)

target_sources(app PRIVATE src/main.c)
