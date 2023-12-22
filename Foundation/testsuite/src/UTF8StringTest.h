//
// UTF8StringTest.h
//
// Definition of the UTF8StringTest class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef UTF8StringTest_INCLUDED
#define UTF8StringTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class UTF8StringTest: public CppUnit::TestCase
{
public:
	UTF8StringTest(const std::string& name);
	~UTF8StringTest();

	void testCompare();
	void testTransform();

	void testEscape();
	void testUnescape();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // UTF8StringTest_INCLUDED
