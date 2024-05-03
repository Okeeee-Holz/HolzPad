cmake_minimum_required(VERSION 3.24.0)

project(HolzPad VERSION 0.5.0)

# compile shader commands
if (WIN32) 
	set(SHADER_COMPILE_COMMANDS_DIR ${CMAKE_SOURCE_DIR}/compileShader.bat)
else () 
	set(SHADER_COMPILE_COMMANDS_DIR ${CMAKE_SOURCE_DIR}/compileShader.sh)
endif ()

# includes and stuff
include_directories(
PUBLIC
	# library local include directory
	${CMAKE_CURRENT_SOURCE_DIR}/include

	# graphics and windowing libraries
	${LIBRARY_PATH}/sdl/include/
	${LIBRARY_PATH}/imgui/

	# utility libraries
	${LIBRARY_PATH}/fmt/include/
)


set (HOLZPAD_SOURCE_FILES 
	"src/main.cpp"
)


# building the executable
if (BUILD_STATIC)
	add_executable(HolzPad "${HOLZPAD_SOURCE_FILES}")
else ()
	add_executable(HolzPad"${HOLZPAD_SOURCE_FILES}")
endif ()


# build error level
if (WIN32) 
	target_compile_options(HolzPad PRIVATE /WX)
else () 
	target_compile_options(HolzPad PRIVATE -Wall -Wextra -Wpedantic)
endif ()


# link some libraries
target_link_libraries(HolzPad
PRIVATE
	# graphics and windowing libraries
	SDL3::SDL3-static
	ImGui

	# utility libraries
	fmt::fmt
)

target_precompile_headers(HolzPad
PRIVATE
    <array>
    <string>
    <string_view>
    <vector>
    <unordered_set>
    <unordered_map>
	<set>
	<map>
	<initializer_list>
	<filesystem>
	<fstream>
	<iostream>
	<typeindex>
	<type_traits>
	<algorithm>
	<chrono>
	<cmath>
	<cstdio>
	<cstdint>
	<cstdlib>
	<functional>
	<stddef.h>
	<stdexcept>
	<stdint.h>
	<type_traits>
	<utility>
	<wchar.h>
	<memory>
    <limits>
)
