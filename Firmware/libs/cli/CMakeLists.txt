#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/cli.c
		${CMAKE_CURRENT_LIST_DIR}/cli.h
)
