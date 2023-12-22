//
// NamedMutexTest.h
//
// Definition of the NamedMutexTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef NamedMutexTest_INCLUDED
#define NamedMutexTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class NamedMutexTest: public CppUnit::TestCase
{
public:
	NamedMutexTest(const std::string& name);
	~NamedMutexTest();

	void testLock();
	void testTryLock();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // NamedMutexTest_INCLUDED
