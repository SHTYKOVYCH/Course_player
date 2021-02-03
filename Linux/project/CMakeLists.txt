cmake_minimum_required(VERSION 3.0)

set(PROJECT Simple_Player)

project(${PROJECT})

set(HEADERS
	headers/DecodeError.h
	headers/OpenFile.h
	headers/ReadSceneNum.h
	headers/Scene.h
	headers/Check.h
	headers/Sound.h
	headers/Graphics.h)

set(SOURCES
	executable/main.c
	executable/OpenFile.c
	executable/DecodeError.c
	executable/ReadSceneNum.c
	executable/Scene.c
	executable/Check.c
	executable/Sound.c
	executable/Graphics.c)

set( GCC_FLAGS "" )

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_FLAGS}" )

add_executable(${PROJECT}  ${HEADERS} ${SOURCES} )

include_directories("headers")
include_directories("executable")
include_directories(".")
target_link_libraries( ${PROJECT} m )
target_link_libraries( ${PROJECT} libSDL2.a )
target_link_libraries( ${PROJECT} GL )
target_link_libraries( ${PROJECT} dl )
target_link_libraries( ${PROJECT} asound )
target_link_libraries( ${PROJECT} pthread )
target_link_libraries( ${PROJECT} pulse-simple )
target_link_libraries( ${PROJECT} pulse )
target_link_libraries( ${PROJECT} X11 )
target_link_libraries( ${PROJECT} Xext )
target_link_libraries( ${PROJECT} Xcursor )
target_link_libraries( ${PROJECT} Xinerama )
target_link_libraries( ${PROJECT} Xi )
target_link_libraries( ${PROJECT} Xrandr )
target_link_libraries( ${PROJECT} Xss )
target_link_libraries( ${PROJECT} Xxf86vm )
target_link_libraries( ${PROJECT} drm )
target_link_libraries( ${PROJECT} gbm )
target_link_libraries( ${PROJECT} wayland-egl )
target_link_libraries( ${PROJECT} wayland-client )
target_link_libraries( ${PROJECT} wayland-cursor )
target_link_libraries( ${PROJECT} xkbcommon )
target_link_libraries( ${PROJECT} rt )
target_link_libraries( ${PROJECT} pthread )
