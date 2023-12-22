//
// DateTimeTest.h
//
// Definition of the DateTimeTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef DateTimeTest_INCLUDED
#define DateTimeTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class DateTimeTest: public CppUnit::TestCase
{
public:
	DateTimeTest(const std::string& name);
	~DateTimeTest();

	void testTimestamp();
	void testJulian();
	void testGregorian();
	void testConversions();
	void testStatics();
	void testCalcs();
	void testAMPM();
	void testRelational();
	void testArithmetics();
	void testSwap();
	void testUsage();
	void testSetYearDay();
	void testIsValid();
	void testDayOfWeek();
	void testIncrementDecrement();
	void testUTC();
	void testLeapSeconds();
	void testTM();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // DateTimeTest_INCLUDED
