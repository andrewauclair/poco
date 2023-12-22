//
// FoundationTestSuite.h
//
// Definition of the FoundationTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef FoundationTestSuite_INCLUDED
#define FoundationTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class FoundationTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // FoundationTestSuite_INCLUDED
