//
// ConditionTest.h
//
// Definition of the ConditionTest class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ConditionTest_INCLUDED
#define ConditionTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class ConditionTest: public CppUnit::TestCase
{
public:
	ConditionTest(const std::string& name);
	~ConditionTest();

	void testSignal();
	void testBroadcast();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // ConditionTest_INCLUDED
