cmake_minimum_required(VERSION 3.10)

project(editor)

include_directories(include)
include_directories(${LIGHT_INCLUDE})

file(GLOB sources sources/*)

add_executable(editor ${sources})

target_link_libraries(editor light)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)