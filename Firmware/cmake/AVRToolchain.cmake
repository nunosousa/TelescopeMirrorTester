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

#set(CMAKE_C_FLAGS_RELEASE "-p -g -O2" CACHE STRING "")
#set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-p -g -O2" CACHE STRING "")
#set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "-p -g -O2" CACHE STRING "")

## AVR Chip Configuration
# 16Mhz, this should match the crystal on your board,
# I use 8Mhz and 3.3V for the lowest power consumption
set(F_CPU 16000000UL)
# CPU, you can find the list here:
# https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html
set(MCU atmega328p)
# Default Baudrate for UART, read avr include/util/setbaud.h for usage
set(BAUD 9600)
# The programmer to use, read avrdude manual for list
set(PROG_TYPE avrispmkII)

# AVR Fuses, must be in concordance with your hardware and F_CPU
# http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega328p
set(E_FUSE 0xfd)
set(H_FUSE 0xda)
set(L_FUSE 0xfd)
set(LOCK_BIT 0xff)
