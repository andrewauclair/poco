//
// SharedLibraryTestSuite.h
//
// Definition of the SharedLibraryTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef SharedLibraryTestSuite_INCLUDED
#define SharedLibraryTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class SharedLibraryTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // SharedLibraryTestSuite_INCLUDED
