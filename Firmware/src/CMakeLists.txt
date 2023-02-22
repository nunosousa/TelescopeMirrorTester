#=============================
# Define targets
#=============================
add_executable(firmware main.c)

set_target_properties(firmware
	PROPERTIES
		OUTPUT_NAME firmware.elf
)

add_subdirectory(libs)

add_library(firmwareBuildInfo STATIC)
target_link_libraries(firmware
	PRIVATE
		firmwareBuildInfo
)

#=============================
# Clean extra files
#=============================
set_directory_properties(
	PROPERTIES
		ADDITIONAL_CLEAN_FILES "firmware.hex;firmware.eeprom;firmware.lst"
)
