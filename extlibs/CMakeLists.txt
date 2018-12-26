cmake_minimum_required(VERSION 3.10)

add_subdirectory(sfml sfml)

add_subdirectory(lua lua)


set(SFML_Dir "${CMAKE_SOURCE_DIR}/extlibs/sfml/include" CACHE INTERNAL "SFML include location")
set(LUA_Dir "${CMAKE_SOURCE_DIR}/extlibs/lua/lua" CACHE INTERNAL "Lua include location")
set(ENTT_Dir "${CMAKE_SOURCE_DIR}/extlibs/entt/src" CACHE INTERNAL "Entt include location")