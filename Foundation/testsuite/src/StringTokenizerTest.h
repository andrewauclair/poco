//
// StringTokenizerTest.h
//
// Definition of the StringTokenizerTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//

#ifndef StringTokenizerTest_INCLUDED
#define StringTokenizerTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class StringTokenizerTest: public CppUnit::TestCase
{
public:
	StringTokenizerTest(const std::string& name);
	~StringTokenizerTest();

	void testStringTokenizer();
	void testFind();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};

#endif // StringTokenizerTest_INCLUDED
