#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/motor_control.c
		${CMAKE_CURRENT_LIST_DIR}/motor_control.h
)
