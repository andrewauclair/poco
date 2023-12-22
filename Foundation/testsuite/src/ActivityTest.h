//
// ActivityTest.h
//
// Definition of the ActivityTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ActivityTest_INCLUDED
#define ActivityTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class ActivityTest: public CppUnit::TestCase
{
public:
	ActivityTest(const std::string& name);
	~ActivityTest();

	void testActivity();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // ActivityTest_INCLUDED
