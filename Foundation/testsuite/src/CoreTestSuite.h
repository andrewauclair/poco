//
// CoreTestSuite.h
//
// Definition of the CoreTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef CoreTestSuite_INCLUDED
#define CoreTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif

class CoreTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // CoreTestSuite_INCLUDED
