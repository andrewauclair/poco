//
// ThreadLocalTest.h
//
// Definition of the ThreadLocalTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ThreadLocalTest_INCLUDED
#define ThreadLocalTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class ThreadLocalTest: public CppUnit::TestCase
{
public:
	ThreadLocalTest(const std::string& name);
	~ThreadLocalTest();

	void testLocality();
	void testAccessors();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // ThreadLocalTest_INCLUDED
