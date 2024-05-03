#ifndef POCO_FOUNDATION_MODULE_INCLUDES_H
#define POCO_FOUNDATION_MODULE_INCLUDES_H

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#include <type_traits>
#include <format>
#include <chrono>
#include <typeinfo>
#include <stdexcept>
#include <iterator>

#if defined(__clang__) || (defined (__GNUC__) && (__GNUC__ >= 3))
#	if (__cplusplus >= 201703L)
#		if __has_include(<cxxabi.h>)
#			include <typeinfo>
#			include <cxxabi.h>
#			include <cstdlib>
#			define POCO_HAVE_CXXABI_H
#		endif // __has_include(<cxxabi.h>)
#	endif // __cplusplus >= 201703L
#endif // defined(__clang__) || (defined (__GNUC__) && (__GNUC__ >= 3))

#endif
