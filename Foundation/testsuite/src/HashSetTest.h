//
// HashSetTest.h
//
// Definition of the HashSetTest class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef HashSetTest_INCLUDED
#define HashSetTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class HashSetTest: public CppUnit::TestCase
{
public:
	HashSetTest(const std::string& name);
	~HashSetTest();

	void testInsert();
	void testErase();
	void testIterator();
	void testConstIterator();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // HashSetTest_INCLUDED
