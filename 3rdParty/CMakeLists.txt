cmake_minimum_required (VERSION 3.24.0)

project(BuildLibraries)

if (BUILD_STATIC)
	option(SDL_SHARED "Build a shared version of SDL" OFF)
	option(SDL_STATIC "Build a static version of SDL" ON)
	option(IMGUI_BUILD_STATIC "Build ImGUI statically" ON)
else ()
	option(SDL_SHARED "Build a shared version of SDL" ON)
	option(SDL_STATIC "Build a static version of SDL" OFF)
	option(IMGUI_BUILD_STATIC "Build ImGUI statically" OFF)
endif ()

add_subdirectory("sdl")
add_subdirectory("imgui")
add_subdirectory("fmt")
