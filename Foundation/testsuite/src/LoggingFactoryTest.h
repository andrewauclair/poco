//
// LoggingFactoryTest.h
//
// Definition of the LoggingFactoryTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef LoggingFactoryTest_INCLUDED
#define LoggingFactoryTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class LoggingFactoryTest: public CppUnit::TestCase
{
public:
	LoggingFactoryTest(const std::string& name);
	~LoggingFactoryTest();

	void testBuiltins();
	void testCustom();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // LoggingFactoryTest_INCLUDED
