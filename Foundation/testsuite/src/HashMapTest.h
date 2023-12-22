//
// HashMapTest.h
//
// Definition of the HashMapTest class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef HashMapTest_INCLUDED
#define HashMapTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class HashMapTest: public CppUnit::TestCase
{
public:
	HashMapTest(const std::string& name);
	~HashMapTest();

	void testInsert();
	void testErase();
	void testIterator();
	void testConstIterator();
	void testIndex();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // HashMapTest_INCLUDED
