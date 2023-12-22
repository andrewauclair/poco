//
// TextIteratorTest.h
//
// Definition of the TextIteratorTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TextIteratorTest_INCLUDED
#define TextIteratorTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class TextIteratorTest: public CppUnit::TestCase
{
public:
	TextIteratorTest(const std::string& name);
	~TextIteratorTest();

	void testEmptyLatin1();
	void testOneLatin1();
	void testLatin1();
	void testEmptyUTF8();
	void testOneUTF8();
	void testUTF8();
	void testUTF8Supplementary();
	void testUTF16Supplementary();
	void testSwap();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // TextIteratorTest_INCLUDED
