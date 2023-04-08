#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/limit_switch.c
		${CMAKE_CURRENT_LIST_DIR}/limit_switch.h
)
