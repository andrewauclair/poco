//
// UUIDTestSuite.h
//
// Definition of the UUIDTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef UUIDTestSuite_INCLUDED
#define UUIDTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class UUIDTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // UUIDTestSuite_INCLUDED
