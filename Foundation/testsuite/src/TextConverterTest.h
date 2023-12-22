//
// TextConverterTest.h
//
// Definition of the TextConverterTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TextConverterTest_INCLUDED
#define TextConverterTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class TextConverterTest: public CppUnit::TestCase
{
public:
	TextConverterTest(const std::string& name);
	~TextConverterTest();

	void testIdentityASCII();
	void testIdentityUTF8();
	void testUTF8toASCII();
	void testLatin1toUTF8();
	void testLatin2toUTF8();
	void testLatin9toUTF8();
	void testCP1250toUTF8();
	void testCP1251toUTF8();
	void testCP1252toUTF8();
	void testErrors();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // TextConverterTest_INCLUDED
