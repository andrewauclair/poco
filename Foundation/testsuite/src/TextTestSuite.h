//
// TextTestSuite.h
//
// Definition of the TextTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TextTestSuite_INCLUDED
#define TextTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class TextTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // TextTestSuite_INCLUDED
