//
// Bugcheck.h
//
// Library: Foundation
// Package: Core
// Module:  Bugcheck
//
// Definition of the Bugcheck class and the self-testing macros.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Bugcheck_INCLUDED
#define Foundation_Bugcheck_INCLUDED


#include "Poco/Foundation.h"
#include <string>
#include <cstdlib>
#if defined(_DEBUG)
#	include <iostream>
#endif


POCO_MODULES_EXPORT_Foundation namespace Poco {


POCO_MODULES_EXPORT_Foundation class Foundation_API Bugcheck
	/// This class provides some static methods that are
	/// used by the
	/// poco_assert_dbg(), poco_assert(), poco_check_ptr(),
	/// poco_bugcheck() and poco_unexpected() macros.
	/// You should not invoke these methods
	/// directly. Use the macros instead, as they
	/// automatically provide useful context information.
{
public:
	[[noreturn]] static void assertion(const char* cond, const char* file, int line, const char* text = 0);
		/// An assertion failed. Break into the debugger, if
		/// possible, then throw an AssertionViolationException.

	[[noreturn]] static void nullPointer(const char* ptr, const char* file, int line);
		/// An null pointer was encountered. Break into the debugger, if
		/// possible, then throw an NullPointerException.

	[[noreturn]] static void bugcheck(const char* file, int line);
		/// An internal error was encountered. Break into the debugger, if
		/// possible, then throw an BugcheckException.

	[[noreturn]] static void bugcheck(const char* msg, const char* file, int line);
		/// An internal error was encountered. Break into the debugger, if
		/// possible, then throw an BugcheckException.

	static void unexpected(const char* file, int line);
		/// An exception was caught in a destructor. Break into debugger,
		/// if possible and report exception. Must only be called from
		/// within a catch () block as it rethrows the exception to
		/// determine its class.

	static void debugger(const char* file, int line);
		/// An internal error was encountered. Break into the debugger, if
		/// possible.

	static void debugger(const char* msg, const char* file, int line);
		/// An internal error was encountered. Break into the debugger, if
		/// possible.

protected:
	static std::string what(const char* msg, const char* file, int line, const char* text = 0);
};


} // namespace Poco




//
// poco_static_assert
//
// The following was ported from <boost/static_assert.hpp>
//


template <bool x>
struct POCO_STATIC_ASSERTION_FAILURE;


template <>
struct POCO_STATIC_ASSERTION_FAILURE<true>
{
	enum
	{
		value = 1
	};
};


template <int x>
struct poco_static_assert_test
{
};


#include "Poco/BugcheckAsserts.h"



#endif // Foundation_Bugcheck_INCLUDED
