//
// NDCTest.h
//
// Definition of the NDCTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef NDCTest_INCLUDED
#define NDCTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class NDCTest: public CppUnit::TestCase
{
public:
	NDCTest(const std::string& name);
	~NDCTest();

	void testNDC();
	void testNDCScope();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // NDCTest_INCLUDED
