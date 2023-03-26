#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/pca9535.c
		${CMAKE_CURRENT_LIST_DIR}/pca9535.h
)
