cmake_minimum_required(VERSION 3.10)
project(test)

include_directories(${LIGHT_INCLUDE})

file(GLOB sources sources/*)

add_executable(test ${sources})
target_link_libraries(test lualib
        sfml-audio
        sfml-system
        sfml-window
        sfml-network
        sfml-graphics)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)