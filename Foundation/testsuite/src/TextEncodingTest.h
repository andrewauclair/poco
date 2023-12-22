//
// TextEncodingTest.h
//
// Definition of the TextEncodingTest class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TextEncodingTest_INCLUDED
#define TextEncodingTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class TextEncodingTest: public CppUnit::TestCase
{
public:
	TextEncodingTest(const std::string& name);
	~TextEncodingTest();

	void testTextEncoding();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // TextEncodingTest_INCLUDED
