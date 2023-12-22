//
// ZLibTest.h
//
// Definition of the ZLibTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ZLibTest_INCLUDED
#define ZLibTest_INCLUDED

#include "CppUnit/CppAsserts.h"
#include "CppUnit/CppTestMacros.h"

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class ZLibTest: public CppUnit::TestCase
{
public:
	ZLibTest(const std::string& name);
	~ZLibTest();

	void testDeflate1();
	void testDeflate2();
	void testDeflate3();
	void testDeflate4();
	void testGzip1();
	void testGzip2();
	void testGzip3();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // ZLibTest_INCLUDED
