//
// CacheTestSuite.h
//
// Definition of the CacheTestSuite class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef CacheTestSuite_INCLUDED
#define CacheTestSuite_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class CacheTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // CacheTestSuite_INCLUDED
