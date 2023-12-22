//
// DigestStreamTest.h
//
// Definition of the DigestStreamTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef DigestStreamTest_INCLUDED
#define DigestStreamTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class DigestStreamTest: public CppUnit::TestCase
{
public:
	DigestStreamTest(const std::string& name);
	~DigestStreamTest();

	void testInputStream();
	void testOutputStream1();
	void testOutputStream2();
	void testToFromHex();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // DigestStreamTest_INCLUDED
