cmake_minimum_required(VERSION 3.16)
project(gilded_rose)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
aux_source_directory(src SRC_FILES)

add_library(gilded_rose SHARED ${SRC_FILES})

add_executable(main main.cpp ${SRC_FILES})

add_subdirectory(test)