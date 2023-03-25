#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/cbuffer.c
		${CMAKE_CURRENT_LIST_DIR}/cbuffer.h
)
