//
// LogStreamTest.h
//
// Definition of the LogStreamTest class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef LogStreamTest_INCLUDED
#define LogStreamTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class LogStreamTest: public CppUnit::TestCase
{
public:
	LogStreamTest(const std::string& name);
	~LogStreamTest();

	void testLogStream();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // LogStreamTest_INCLUDED
