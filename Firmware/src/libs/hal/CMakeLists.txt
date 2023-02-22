#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/hal.c
		${CMAKE_CURRENT_LIST_DIR}/hal.h
)
