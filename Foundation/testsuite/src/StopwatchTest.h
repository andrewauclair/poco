//
// StopwatchTest.h
//
// Definition of the StopwatchTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef StopwatchTest_INCLUDED
#define StopwatchTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class StopwatchTest: public CppUnit::TestCase
{
public:
	StopwatchTest(const std::string& name);
	~StopwatchTest();

	void testStopwatch();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // StopwatchTest_INCLUDED
