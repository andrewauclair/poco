//
// NotificationsTestSuite.h
//
// Definition of the NotificationsTestSuite class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef NotificationsTestSuite_INCLUDED
#define NotificationsTestSuite_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestSuite.h"
#endif


class NotificationsTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // NotificationsTestSuite_INCLUDED
