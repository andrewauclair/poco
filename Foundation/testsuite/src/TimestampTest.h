//
// TimestampTest.h
//
// Definition of the TimestampTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TimestampTest_INCLUDED
#define TimestampTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class TimestampTest: public CppUnit::TestCase
{
public:
	TimestampTest(const std::string& name);
	~TimestampTest();

	void testTimestamp();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // TimestampTest_INCLUDED
