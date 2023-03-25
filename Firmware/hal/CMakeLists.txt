#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/twi_master.c
		${CMAKE_CURRENT_LIST_DIR}/twi_master.h
		${CMAKE_CURRENT_LIST_DIR}/uart.c
		${CMAKE_CURRENT_LIST_DIR}/uart.h
)
