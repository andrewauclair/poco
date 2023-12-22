//
// FilesystemTestSuite.h
//
// Definition of the FilesystemTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef FilesystemTestSuite_INCLUDED
#define FilesystemTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif

class FilesystemTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // FilesystemTestSuite_INCLUDED
