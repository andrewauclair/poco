//
// ClassLoaderTest.h
//
// Definition of the ClassLoaderTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ClassLoaderTest_INCLUDED
#define ClassLoaderTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class ClassLoaderTest: public CppUnit::TestCase
{
public:
	ClassLoaderTest(const std::string& name);
	~ClassLoaderTest();

	void testClassLoader1();
	void testClassLoader2();
	void testClassLoader3();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
	static std::string getFullName(const std::string& libName);
};


#endif // ClassLoaderTest_INCLUDED
