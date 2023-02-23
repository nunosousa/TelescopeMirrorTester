# Use AVR GCC toolchain
find_program(AVR_OBJCOPY avr-objcopy REQUIRED)
find_program(AVR_SIZE_TOOL avr-size REQUIRED)
find_program(AVR_OBJDUMP avr-objdump REQUIRED)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_SYSTEM_VERSION 1)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_ASM_COMPILER avr-gcc)

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

#add_definitions(-DFOOBAR_VERSION=\"${FooBar_VERSION}\")

# Pass defines to compiler
add_compile_definitions(
    -DF_CPU=${F_CPU}
    -DBAUD=${BAUD}
)

add_compile_options(
	-mmcu=${MCU} # MCU
	-Os # optimize
	-Wall # enable warnings
	-Wno-main
	-Wundef
	-pedantic
	-Wstrict-prototypes
	-Werror
	-Wfatal-errors
	-Wl,--relax,--gc-sections
	-funsigned-char # a few optimizations
	-funsigned-bitfields
	-fpack-struct
	-fshort-enums
	-ffunction-sections
	-fdata-sections
	-fno-split-wide-types
	-fno-tree-scev-cprop
)

# mmcu MUST be passed to bot the compiler and linker, this handle the linker
set(CMAKE_EXE_LINKER_FLAGS -mmcu=${MCU})

# Strip binary for upload
add_custom_target(strip ALL avr-strip ${PRODUCT_NAME}.elf DEPENDS ${PRODUCT_NAME})

# Transform binary into hex file, we ignore the eeprom segments in the step
add_custom_target(hex ALL avr-objcopy -R .eeprom -O ihex ${PRODUCT_NAME}.elf ${PRODUCT_NAME}.hex DEPENDS strip)
# Transform binary into hex file, this is the eeprom part (empty if you don't
# use eeprom static variables)
add_custom_target(eeprom avr-objcopy -j .eeprom  --set-section-flags=.eeprom="alloc,load"  --change-section-lma .eeprom=0 -O ihex ${PRODUCT_NAME}.elf ${PRODUCT_NAME}.eep DEPENDS strip)

# Upload the firmware with avrdude
add_custom_target(upload avrdude  -c ${PROG_TYPE} -p ${MCU} -U flash:w:${PRODUCT_NAME}.hex DEPENDS hex)

# Upload the eeprom with avrdude
add_custom_target(upload_eeprom avrdude -c ${PROG_TYPE} -p ${MCU}  -U eeprom:w:${PRODUCT_NAME}.eep DEPENDS eeprom)

# Burn fuses
add_custom_target(fuses avrdude -c ${PROG_TYPE} -p ${MCU}  -U lfuse:w:${L_FUSE}:m -U hfuse:w:${H_FUSE}:m -U efuse:w:${E_FUSE}:m -U lock:w:${LOCK_BIT}:m )
