//
// HashingTestSuite.h
//
// Definition of the HashingTestSuite class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef HashingTestSuite_INCLUDED
#define HashingTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif

class HashingTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // HashingTestSuite_INCLUDED
