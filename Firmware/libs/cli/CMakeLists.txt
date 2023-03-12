#=============================
# Add sources
#=============================
target_sources(cli
	PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/cli_defs.h
		${CMAKE_CURRENT_LIST_DIR}/cli.c
		${CMAKE_CURRENT_LIST_DIR}/cli.h
)
