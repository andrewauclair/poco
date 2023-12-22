//
// UniqueExpireLRUCacheTest.h
//
// Tests for UniqueExpireLRUCache
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//

#ifndef UniqueExpireLRUCacheTest_INCLUDED
#define UniqueExpireLRUCacheTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class UniqueExpireLRUCacheTest: public CppUnit::TestCase
{
public:
	UniqueExpireLRUCacheTest(const std::string& name);
	~UniqueExpireLRUCacheTest();

	void testClear();
	void testAccessClear();
	void testExpire0();
	void testExpireN();
	void testCacheSize0();
	void testCacheSize1();
	void testCacheSize2();
	void testCacheSizeN();
	void testDuplicateAdd();

	void setUp();
	void tearDown();
	static CppUnit::Test* suite();
};


#endif // UniqueExpireLRUCacheTest_INCLUDED
