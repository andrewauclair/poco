//
// CryptTestSuite.h
//
// Definition of the CryptTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef CryptTestSuite_INCLUDED
#define CryptTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class CryptTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // CryptTestSuite_INCLUDED
