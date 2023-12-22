//
// ThreadingTestSuite.h
//
// Definition of the ThreadingTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ThreadingTestSuite_INCLUDED
#define ThreadingTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class ThreadingTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // ThreadingTestSuite_INCLUDED
