#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/nec_ir.c
		${CMAKE_CURRENT_LIST_DIR}/nec_ir.h
)
