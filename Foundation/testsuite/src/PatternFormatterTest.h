//
// PatternFormatterTest.h
//
// Definition of the PatternFormatterTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef PatternFormatterTest_INCLUDED
#define PatternFormatterTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class PatternFormatterTest: public CppUnit::TestCase
{
public:
	PatternFormatterTest(const std::string& name);
	~PatternFormatterTest();

	void testPatternFormatter();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // PatternFormatterTest_INCLUDED
