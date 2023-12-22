//
// AutoReleasePoolTest.h
//
// Definition of the AutoReleasePoolTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef AutoReleasePoolTest_INCLUDED
#define AutoReleasePoolTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class AutoReleasePoolTest: public CppUnit::TestCase
{
public:
	AutoReleasePoolTest(const std::string& name);
	~AutoReleasePoolTest();

	void testAutoReleasePool();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // AutoReleasePoolTest_INCLUDED
