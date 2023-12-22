//
// URITestSuite.h
//
// Definition of the URITestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef URITestSuite_INCLUDED
#define URITestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class URITestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // URITestSuite_INCLUDED
