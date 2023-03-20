#=============================
# Define variables
#=============================
## AVR Chip Configuration
# MCU
set(MCU atmega328p)
set(MCU_DUDE m328p)
# 16Mhz, this should match the crystal on the board
set(F_CPU 16000000UL)
# Default Baudrate for UART, read avr include/util/setbaud.h for usage:
# https://www.nongnu.org/avr-libc/user-manual/group__util__setbaud.html
set(BAUD 9600)
# The programmer to use, read avrdude manual 
# https://avrdudes.github.io/avrdude/
set(PROG_TYPE usbasp)
# AVR Fuses, must be in concordance with your hardware and F_CPU
# http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega328p
set(E_FUSE 0xfd)
set(H_FUSE 0xda)
set(L_FUSE 0xfd)
set(LOCK_BIT 0xff)

# Serial port receive buffer size
set(RX_BUFSIZE 80)

#=============================
# Configure main target
#=============================
set_target_properties(firmware
	PROPERTIES
		OUTPUT_NAME firmware.elf
)

target_compile_definitions(firmware
	PRIVATE
		F_CPU=${F_CPU}
    	BAUD=${BAUD}
		RX_BUFSIZE=${RX_BUFSIZE}
)

target_compile_definitions(cli
	PRIVATE
		RX_BUFSIZE=${RX_BUFSIZE}
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

# https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html
target_link_options(firmware
	PRIVATE
		-mmcu=${MCU}
		-Wl,-Map,firmware.map
)

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
# Display information from the build object file
add_custom_target(dump
	ALL
		${AVR_OBJDUMP}
			--source
			--line-numbers
			--full-contents
			--section-headers
			--target=elf32-avr
			firmware.elf
			> firmware.lst
		DEPENDS
			firmware
)

# Strip binary for upload
add_custom_target(strip
	ALL
		${AVR_STRIP}
			-v
			--strip-all
			--input-target=elf32-avr
			--output-target=elf32-avr
			-o firmware_stripped.elf
			firmware.elf
	DEPENDS
		firmware
)

# Size of the produced binary for upload
add_custom_target(size
	ALL
		${AVR_SIZE}
			--mcu=${MCU}
			--format=avr
			--radix=10
			--target=elf32-avr
			--common
			firmware_stripped.elf
	DEPENDS
		strip
)

# Transform binary into hex file, we ignore the eeprom segments in the step
add_custom_target(hex
	ALL
		${AVR_OBJCOPY}
			-v
			--input-target=elf32-avr
			--output-target=ihex
			--remove-section=.eeprom
			firmware_stripped.elf
			firmware.hex
	DEPENDS
		strip
)

# Transform binary into hex file, this is the eeprom part (empty if you don't
# use eeprom static variables)
add_custom_target(eeprom
	${AVR_OBJCOPY}
		-v
		--input-target=elf32-avr
		--output-target=ihex
		--only-section=.eeprom
		--set-section-flags .eeprom="alloc,load"
		--change-section-lma .eeprom=0
		firmware_stripped.elf
		firmware.eep
	DEPENDS
		strip
)

# Upload the firmware
add_custom_target(upload
	${AVR_DUDE}
		-v
		-c ${PROG_TYPE}
		-p ${MCU_DUDE}
		-U flash:w:firmware.hex
	DEPENDS
		hex
)

# Upload the eeprom
add_custom_target(upload_eeprom
	${AVR_DUDE}
		-v
		-c ${PROG_TYPE}
		-p ${MCU_DUDE}
		-U eeprom:w:firmware.eep
	DEPENDS
		eeprom
)

# Burn fuses
add_custom_target(fuses
	${AVR_DUDE}
		-v
		-c ${PROG_TYPE}
		-p ${MCU_DUDE}
		-U lfuse:w:${L_FUSE}:m
		-U hfuse:w:${H_FUSE}:m
		-U efuse:w:${E_FUSE}:m
		-U lock:w:${LOCK_BIT}:m
)
