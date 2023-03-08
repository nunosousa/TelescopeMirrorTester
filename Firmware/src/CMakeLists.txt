#=============================
# Define variables
#=============================
## AVR Chip Configuration
# MCU
set(MCU atmega328p)
# 16Mhz, this should match the crystal on the board
set(F_CPU 16000000UL)
# Default Baudrate for UART, read avr include/util/setbaud.h for usage:
# https://www.nongnu.org/avr-libc/user-manual/group__util__setbaud.html
set(BAUD 9600)
# The programmer to use, read avrdude manual for list
set(PROG_TYPE avrispmkII)

# AVR Fuses, must be in concordance with your hardware and F_CPU
# http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega328p
set(E_FUSE 0xfd)
set(H_FUSE 0xda)
set(L_FUSE 0xfd)
set(LOCK_BIT 0xff)

#=============================
# Define targets
#=============================
add_library(firmwareBuildInfo STATIC)

add_executable(firmware main.c)

set_target_properties(firmware
	PROPERTIES
		OUTPUT_NAME firmware.elf
)

target_link_libraries(firmware
	PRIVATE
		firmwareBuildInfo
)

target_compile_definitions(firmware
	PRIVATE
		F_CPU=${F_CPU}
    	BAUD=${BAUD}
)
# Info on configurations:
# https://gcc.gnu.org/wiki/avr-gcc
# https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html
# https://gcc.gnu.org/onlinedocs/gcc/Option-Index.html
target_compile_options(firmware
	PRIVATE
		-mmcu=${MCU}
		-Wall
		-Wextra
		-Wpedantic
		-Wfatal-errors
)

target_link_options(firmware
	PRIVATE
		-mmcu=${MCU}
)

add_subdirectory(libs)
#add_subdirectory(code...)

#=============================
# Clean extra files
#=============================
set_directory_properties(
	PROPERTIES
		ADDITIONAL_CLEAN_FILES "firmware.hex;firmware.eeprom;firmware.lst"
)

#=============================
# Define custom targets
#=============================
# Strip binary for upload
add_custom_target(strip
	ALL
		${AVR_STRIP} firmware.elf
	DEPENDS
		firmware
)

# Transform binary into hex file, we ignore the eeprom segments in the step
add_custom_target(hex
	ALL
		${AVR_OBJCOPY} -R .eeprom -O ihex firmware.elf firmware.hex
	DEPENDS
		strip
)

# Transform binary into hex file, this is the eeprom part (empty if you don't
# use eeprom static variables)
add_custom_target(eeprom
	${AVR_OBJCOPY} -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 -O ihex firmware.elf firmware.eep
	DEPENDS
		strip
)

# Upload the firmware
add_custom_target(upload
	${AVR_DUDE} -c ${PROG_TYPE} -p ${MCU} -U flash:w:firmware.hex
	DEPENDS
		hex
)

# Upload the eeprom
add_custom_target(upload_eeprom
	${AVR_DUDE} -c ${PROG_TYPE} -p ${MCU} -U eeprom:w:firmware.eep
	DEPENDS
		eeprom
)

# Burn fuses
add_custom_target(fuses
	${AVR_DUDE} -c ${PROG_TYPE} -p ${MCU} -U lfuse:w:${L_FUSE}:m -U hfuse:w:${H_FUSE}:m -U efuse:w:${E_FUSE}:m -U lock:w:${LOCK_BIT}:m
)
