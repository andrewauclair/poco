//
// SHA1EngineTest.h
//
// Definition of the SHA1EngineTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef SHA1EngineTest_INCLUDED
#define SHA1EngineTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class SHA1EngineTest: public CppUnit::TestCase
{
public:
	SHA1EngineTest(const std::string& name);
	~SHA1EngineTest();

	void testSHA1();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // SHA1EngineTest_INCLUDED
