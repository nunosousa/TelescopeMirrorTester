#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/main.c
		${CMAKE_CURRENT_LIST_DIR}/main.h
		${CMAKE_CURRENT_LIST_DIR}/ir_remote.c
		${CMAKE_CURRENT_LIST_DIR}/ir_remote.h
		${CMAKE_CURRENT_LIST_DIR}/cli_commands.c
		${CMAKE_CURRENT_LIST_DIR}/cli_commands.h
)
