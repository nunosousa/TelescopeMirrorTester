#=============================
# Preamble
#=============================
cmake_minimum_required(VERSION 3.12)
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
# Main targets built by this project
#=============================
add_subdirectory(src)






set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release Profile)
