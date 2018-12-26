cmake_minimum_required(VERSION 3.10)
project(light)

set(CMAKE_CXX_STANDARD 17)


message(${ENTT_Dir})

include_directories(include)
include_directories(${ENTT_Dir})
include_directories(${LUA_Dir})
include_directories(${SFML_Dir})

file(GLOB core sources/core/*)
file(GLOB sources sources/*.cpp)

add_library(light STATIC ${core} ${src})

target_link_libraries(light
        sfml-audio
        sfml-system
        sfml-window
        sfml-network
        sfml-graphics)