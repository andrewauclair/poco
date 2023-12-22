//
// StreamConverterTest.h
//
// Definition of the StreamConverterTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef StreamConverterTest_INCLUDED
#define StreamConverterTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class StreamConverterTest: public CppUnit::TestCase
{
public:
	StreamConverterTest(const std::string& name);
	~StreamConverterTest();

	void testIdentityASCIIIn();
	void testIdentityASCIIOut();
	void testIdentityUTF8In();
	void testIdentityUTF8Out();
	void testUTF8toASCIIIn();
	void testUTF8toASCIIOut();
	void testLatin1toUTF8In();
	void testLatin1toUTF8Out();
	void testErrorsIn();
	void testErrorsOut();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // StreamConverterTest_INCLUDED
