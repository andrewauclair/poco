//
// DateTimeTestSuite.h
//
// Definition of the DateTimeTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef DateTimeTestSuite_INCLUDED
#define DateTimeTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class DateTimeTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // DateTimeTestSuite_INCLUDED
