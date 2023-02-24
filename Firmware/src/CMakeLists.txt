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

add_compile_definitions(
    -DF_CPU=${F_CPU}
    -DBAUD=${BAUD}
)

add_compile_options(
	-mmcu=${MCU}
	-Os
	-Wall
	-Wno-main
	-Wundef
	-pedantic
	-Wstrict-prototypes
	-Werror
	-Wfatal-errors
	-Wl,--relax,--gc-sections
	-funsigned-char
	-funsigned-bitfields
	-fpack-struct
	-fshort-enums
	-ffunction-sections
	-fdata-sections
	-fno-split-wide-types
	-fno-tree-scev-cprop
)

add_link_options(
	-mmcu=${MCU}
)

add_subdirectory(libs)

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
