//
// ClockTest.h
//
// Definition of the ClockTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ClockTest_INCLUDED
#define ClockTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class ClockTest: public CppUnit::TestCase
{
public:
	ClockTest(const std::string& name);
	~ClockTest();

	void testClock();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // ClockTest_INCLUDED
