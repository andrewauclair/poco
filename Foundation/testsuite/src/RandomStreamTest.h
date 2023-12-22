//
// RandomStreamTest.h
//
// Definition of the RandomStreamTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef RandomStreamTest_INCLUDED
#define RandomStreamTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class RandomStreamTest: public CppUnit::TestCase
{
public:
	RandomStreamTest(const std::string& name);
	~RandomStreamTest();

	void testStream();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // RandomStreamTest_INCLUDED
