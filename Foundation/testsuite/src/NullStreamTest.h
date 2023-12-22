//
// NullStreamTest.h
//
// Definition of the NullStreamTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef NullStreamTest_INCLUDED
#define NullStreamTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class NullStreamTest: public CppUnit::TestCase
{
public:
	NullStreamTest(const std::string& name);
	~NullStreamTest();

	void testInput();
	void testOutput();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // NullStreamTest_INCLUDED
