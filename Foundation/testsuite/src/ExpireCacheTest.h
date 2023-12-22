//
// ExpireCacheTest.h
//
// Tests for ExpireCache
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//

#ifndef ExpireCacheTest_INCLUDED
#define ExpireCacheTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class ExpireCacheTest: public CppUnit::TestCase
{
public:
	ExpireCacheTest(const std::string& name);
	~ExpireCacheTest();

	void testClear();
	void testDuplicateAdd();
	void testExpire0();
	void testExpireN();
	void testAccessExpireN();
	void testExpireWithHas();
	void testAccessExpireGet();

	void setUp();
	void tearDown();
	static CppUnit::Test* suite();
};


#endif // ExpireCacheTest_INCLUDED
