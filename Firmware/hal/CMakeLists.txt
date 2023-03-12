#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/uart.c
		${CMAKE_CURRENT_LIST_DIR}/uart.h
)
