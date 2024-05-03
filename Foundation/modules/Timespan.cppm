module;

// #include "Poco/Foundation.h"
// #include <cstdint>
// #include <type_traits>
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

export module PocoFoundation:Timespan;

#include "Timespan.cpp"
