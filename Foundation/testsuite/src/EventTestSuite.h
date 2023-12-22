//
// EventTestSuite.h
//
// Definition of the EventTestSuite class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef EventTestSuite_INCLUDED
#define EventTestSuite_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class EventTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // EventTestSuite_INCLUDED
