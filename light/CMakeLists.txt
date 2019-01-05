cmake_minimum_required(VERSION 3.10)
project(light)

set(CMAKE_CXX_STANDARD 17)
set(LIGHT_INCLUDE "${CMAKE_SOURCE_DIR}/light/include" CACHE INTERNAL "light include location" )

include_directories(include)
include_directories(${LUA_ROOT})
include_directories(${BOX2D_INCLUDE})

message("${LUA_ROOT}")

file(GLOB fs sources/fs/*)
file(GLOB core sources/core/*)
file(GLOB systems sources/systems/*)
file(GLOB graphics sources/graphics/*)

add_library(light SHARED ${core} ${graphics} ${systems})

target_link_libraries(light lualib Box2D
        sfml-audio
        sfml-system
        sfml-window
        sfml-network
        sfml-graphics)
		
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)