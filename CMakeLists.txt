cmake_minimum_required(VERSION 3.10)

set(LIGHT "${CMAKE_SOURCE_DIR}/light/include" CACHE INTERNAL "light include location")

#if(CMAKE_SYSTEM_NAME MATCHES "Window")
#    set(CMAKE_EXE_LINKER_FLAGS -static)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
#endif()

set(CMAKE_CXX_STANDARD 17)

set(STATIC_SFML TRUE)
set(BUILD_SHARED_LIBS FALSE)

add_definitions(-DSFML_STATIC)
add_definitions(-D_HAS_AUTO_PTR_ETC)
# set(CMAKE_TOOLCHAIN_FILE "E:/Github/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_subdirectory(extlibs)
add_subdirectory(light light)
add_subdirectory(editor editor)

add_subdirectory(test test)
