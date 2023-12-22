//
// LinearHashTableTest.h
//
// Definition of the LinearHashTableTest class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef LinearHashTableTest_INCLUDED
#define LinearHashTableTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class LinearHashTableTest: public CppUnit::TestCase
{
public:
	LinearHashTableTest(const std::string& name);
	~LinearHashTableTest();

	void testInsert();
	void testErase();
	void testIterator();
	void testConstIterator();
	void testPerformanceInt();
	void testPerformanceStr();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // LinearHashTableTest_INCLUDED
