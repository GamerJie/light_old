cmake_minimum_required(VERSION 3.10)
project(extlibs)

add_subdirectory(lua lua)
add_subdirectory(sfml sfml)
add_subdirectory(box2d box2d)

set(LUA_ROOT "${CMAKE_SOURCE_DIR}/extlibs/Lua/src" CACHE INTERNAL "Lua source location" )
set(BOX2D_INCLUDE "${CMAKE_SOURCE_DIR}/extlibs/Box2D/Include" CACHE INTERNAL "Box2D include location" )
