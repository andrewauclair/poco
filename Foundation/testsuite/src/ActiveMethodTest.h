//
// ActiveMethodTest.h
//
// Definition of the ActiveMethodTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ActiveMethodTest_INCLUDED
#define ActiveMethodTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class ActiveMethodTest: public CppUnit::TestCase
{
public:
	ActiveMethodTest(const std::string& name);
	~ActiveMethodTest();

	void testWait();
	void testCopy();
	void testWaitInterval();
	void testTryWait();
	void testFailure();
	void testVoidOut();
	void testVoidInOut();
	void testVoidIn();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // ActiveMethodTest_INCLUDED
