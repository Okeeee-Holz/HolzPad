/**
 * @file Common.hpp
 * @author Zhile Zhu (zhuzhile08@gmail.com)
 * 
 * @brief File with common utilities
 * 
 * @date 2024-05-03
 * @copyright Copyright (c) 2024
 */

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <cassert>
#include <string>
#include <type_traits>

// utility macros

#define NODISCARD [[nodiscard]]
#define DEPRECATED [[deprecated]]
#define NO_UNIQUE_ADDRESS [[no_unique_address]]

namespace holzpad {

// abbreviations for fixed width integers

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

using uchar = unsigned char; // mostly alternative names, borrowed from ogre
using ushort = unsigned short;
using ulong = unsigned long;

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

// floating point types

using float32 = float;
using float64 = double;
using float128 = long double; // not supported everywhere, so don't really use this

// some other common types

using wchar = wchar_t;
using filepos = fpos_t;
using objectid = uint64;
using uintptr = uintptr_t;
using nullpointer = decltype(nullptr);
using size_type = std::size_t;


// utility functions

template <typename Ty> NODISCARD constexpr inline const void* getAddress(const Ty& type) noexcept {
	return static_cast<const void*>(type);
}

template <class Ty> concept EnumType = std::is_enum_v<Ty>;

// credits to https://gist.github.com/StrikerX3/46b9058d6c61387b3f361ef9d7e00cd4 for these operators!

template<EnumType Enum> constexpr inline Enum operator|(Enum first, Enum second) noexcept {
	return static_cast<Enum>(
		static_cast<std::underlying_type_t<Enum>>(first) |
		static_cast<std::underlying_type_t<Enum>>(second)
	);
}

template<EnumType Enum> Enum constexpr inline operator&(Enum first, Enum second) noexcept {
	return static_cast<Enum>(
		static_cast<std::underlying_type_t<Enum>>(first) &
		static_cast<std::underlying_type_t<Enum>>(second)
	);
}

template<EnumType Enum> Enum constexpr inline operator^(Enum first, Enum second) noexcept {
	return static_cast<Enum>(
		static_cast<std::underlying_type_t<Enum>>(first) ^
		static_cast<std::underlying_type_t<Enum>>(second)
	);
}

template<EnumType Enum> Enum constexpr inline operator~(Enum first) noexcept {
	return static_cast<Enum>(
		~static_cast<std::underlying_type_t<Enum>>(first)
	);
}

template<EnumType Enum> Enum constexpr inline operator|=(Enum& first, Enum second) noexcept {
	return (first = static_cast<Enum>(
		static_cast<std::underlying_type_t<Enum>>(first) |
		static_cast<std::underlying_type_t<Enum>>(second)
	));
}

template<EnumType Enum> Enum constexpr inline operator&=(Enum& first, Enum second) noexcept {
	return (first = static_cast<Enum>(
		static_cast<std::underlying_type_t<Enum>>(first) &
		static_cast<std::underlying_type_t<Enum>>(second)
	));
}

template<EnumType Enum> Enum constexpr inline operator^=(Enum& first, Enum second) noexcept {
	return (first = static_cast<Enum>(
		static_cast<std::underlying_type_t<Enum>>(first) ^
		static_cast<std::underlying_type_t<Enum>>(second)
	));
}

} // namespace holzpad

namespace std {

template<holypad::EnumType Enum> constexpr inline std::string to_string(Enum e) noexcept {
	return std::to_string(static_cast<std::underlying_type_t<Enum>>(e));
}

} // namespace std
