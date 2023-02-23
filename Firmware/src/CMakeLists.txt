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

add_subdirectory(libs)

#=============================
# Clean extra files
#=============================
set_directory_properties(
	PROPERTIES
		ADDITIONAL_CLEAN_FILES "firmware.hex;firmware.eeprom;firmware.lst"
)
