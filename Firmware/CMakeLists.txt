#=============================
# Preamble
#=============================
cmake_minimum_required(VERSION 3.24)
project(controller_board
	LANGUAGES C
	VERSION 0.1
)

#=============================
# Project wide setup
#=============================
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)
set(CMAKE_C_EXTENSIONS NO)

#=============================
# Define targets and links
#=============================
add_library(firmwareBuildInfo STATIC)
add_library(cli STATIC)
add_subdirectory(libs)

add_executable(firmware)
add_subdirectory(hal)
add_subdirectory(src)

target_link_libraries(firmware
	PRIVATE
		firmwareBuildInfo
		cli
)

include(cmake/CMakeLists.txt)
