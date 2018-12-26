cmake_minimum_required(VERSION 3.10)

project(demo)

message(${Light_Dir})

include_directories(include)
include_directories(${Light_Dir})
include_directories(${ENTT_Dir})

file(GLOB sources sources/*)

add_executable(demo ${sources})

target_link_libraries(demo light)