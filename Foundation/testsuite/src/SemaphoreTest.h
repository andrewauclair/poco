//
// SemaphoreTest.h
//
// Definition of the SemaphoreTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef SemaphoreTest_INCLUDED
#define SemaphoreTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class SemaphoreTest: public CppUnit::TestCase
{
public:
	SemaphoreTest(const std::string& name);
	~SemaphoreTest();

	void testInitZero();
	void testInitNonZero();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // SemaphoreTest_INCLUDED
