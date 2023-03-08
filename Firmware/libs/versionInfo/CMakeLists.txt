#=============================
# Add sources
#=============================
configure_file(firmwareBuildInfo.c.in firmwareBuildInfo.c @ONLY)

target_sources(firmwareBuildInfo
	PRIVATE
		${CMAKE_CURRENT_BINARY_DIR}/firmwareBuildInfo.c
		${CMAKE_CURRENT_LIST_DIR}/firmwareBuildInfo.h
)
