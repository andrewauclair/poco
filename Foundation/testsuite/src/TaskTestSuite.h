//
// TaskTestSuite.h
//
// Definition of the TaskTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TaskTestSuite_INCLUDED
#define TaskTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class TaskTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // TaskTestSuite_INCLUDED
