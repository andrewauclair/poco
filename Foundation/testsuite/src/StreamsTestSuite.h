//
// StreamsTestSuite.h
//
// Definition of the StreamsTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef StreamsTestSuite_INCLUDED
#define StreamsTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class StreamsTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // StreamsTestSuite_INCLUDED
