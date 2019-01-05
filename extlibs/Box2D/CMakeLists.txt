cmake_minimum_required(VERSION 2.6)

project(Box2D)

include_directories(Include)

file(GLOB Collision 
	Collision/*.h Collision/*.cpp
	Collision/Shapes/*.h Collision/Shapes/*.cpp)

file(GLOB Common
	Common/*.h Common/*.cpp)

file(GLOB Dynamics
	Dynamics/*.h Dynamics/*.cpp
	Dynamics/Contacts/*.h Dynamics/Contacts/*.cpp
	Dynamics/Joints/*.h Dynamics/Joints/*.cpp)
	
file(GLOB Rope
	Rope/*.h Rope/*.cpp)

	
source_group(Collision Collision/*)
source_group(Collision\\Shapes Collision/Shapes/*)
source_group(Common Common/*)
source_group(Dynamics Dynamics/*)
source_group(Dynamics\\Contacts Dynamics/Contacts/*)
source_group(Dynamics\\Joints Dynamics/Joints/*)
source_group(Rope Rope/*)

add_library(Box2D 
	${Collision}
	${Common}
	${Dynamics}
	${Rope})

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)