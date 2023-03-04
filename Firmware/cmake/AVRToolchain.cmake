# Use AVR GCC toolchain
find_program(AVR_OBJDUMP avr-objdump REQUIRED)
find_program(AVR_STRIP avr-strip REQUIRED)
find_program(AVR_OBJCOPY avr-objcopy REQUIRED)
find_program(AVR_SIZE_TOOL avr-size REQUIRED)
find_program(AVR_DUDE avrdude REQUIRED)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_SYSTEM_VERSION 1)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_ASM_COMPILER avr-gcc)
