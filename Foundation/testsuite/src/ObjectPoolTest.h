//
// ObjectPoolTest.h
//
// Definition of the ObjectPoolTest class.
//
// Copyright (c) 2010-2012, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ObjectPoolTest_INCLUDED
#define ObjectPoolTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class ObjectPoolTest: public CppUnit::TestCase
{
public:
	ObjectPoolTest(const std::string& name);
	~ObjectPoolTest();

	void testObjectPool();
	void testObjectPoolWaitOnBorrowObject();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // ObjectPoolTest_INCLUDED
