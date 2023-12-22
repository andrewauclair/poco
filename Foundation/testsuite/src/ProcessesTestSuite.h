//
// ProcessesTestSuite.h
//
// Definition of the ProcessesTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ProcessesTestSuite_INCLUDED
#define ProcessesTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class ProcessesTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // ProcessesTestSuite_INCLUDED
