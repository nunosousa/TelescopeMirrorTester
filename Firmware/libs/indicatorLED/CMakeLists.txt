#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/indicator_led.c
		${CMAKE_CURRENT_LIST_DIR}/indicator_led.h
)
