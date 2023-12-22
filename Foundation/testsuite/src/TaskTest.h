//
// TaskTest.h
//
// Definition of the TaskTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TaskTest_INCLUDED
#define TaskTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class TaskTest: public CppUnit::TestCase
{
public:
	TaskTest(const std::string& name);
	~TaskTest();

	void testFinish();
	void testCancel1();
	void testCancel2();
	void testCancelNoStart();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // TaskTest_INCLUDED
