#=============================
# Define targets
#=============================
add_executable(firmware main.c)

set_target_properties(firmware
	PROPERTIES
		OUTPUT_NAME firmware.elf
)

configure_file(firmware_version.cpp.in firmware_version.cpp @ONLY)
add_library(firmware_version
	STATIC
		${CMAKE_CURRENT_BINARY_DIR}/firmware_version.cpp
)
target_link_libraries(firmware
	PRIVATE
		firmware_version
)

add_subdirectory(hal)

#=============================
# Clean extra files
#=============================
set_directory_properties(
	PROPERTIES
		ADDITIONAL_CLEAN_FILES "firmware.hex;firmware.eeprom;firmware.lst"
)
