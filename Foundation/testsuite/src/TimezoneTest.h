//
// TimezoneTest.h
//
// Definition of the TimezoneTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TimezoneTest_INCLUDED
#define TimezoneTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class TimezoneTest: public CppUnit::TestCase
{
public:
	TimezoneTest(const std::string& name);
	~TimezoneTest();

	void testTimezone();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // TimezoneTest_INCLUDED
