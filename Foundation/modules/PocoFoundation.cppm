module;

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#include <type_traits>
#include <array>
#include <variant>
#include <vector>
#include <sstream>
#include <algorithm>
#include <locale>
#include <typeinfo>
#include <stdexcept>
#include <iterator>
//#include <format>
//#include <chrono>
// #if defined(__clang__) || (defined (__GNUC__) && (__GNUC__ >= 3))
// #	if (__cplusplus >= 201703L)
// #		if __has_include(<cxxabi.h>)
// #			include <typeinfo>
// #			include <cxxabi.h>
// #			include <cstdlib>
// #			define POCO_HAVE_CXXABI_H
// #		endif // __has_include(<cxxabi.h>)
// #	endif // __cplusplus >= 201703L
// #endif // defined(__clang__) || (defined (__GNUC__) && (__GNUC__ >= 3))
#define POCO_ENABLE_MODULES

export module PocoFoundation;

export import :Exception;
export import :Mutex;
export import :Timestamp;
//export import :Timespan;