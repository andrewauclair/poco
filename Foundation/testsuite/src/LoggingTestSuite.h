//
// LoggingTestSuite.h
//
// Definition of the LoggingTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef LoggingTestSuite_INCLUDED
#define LoggingTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class LoggingTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // LoggingTestSuite_INCLUDED
