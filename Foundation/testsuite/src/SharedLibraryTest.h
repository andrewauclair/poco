//
// SharedLibraryTest.h
//
// Definition of the SharedLibraryTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef SharedLibraryTest_INCLUDED
#define SharedLibraryTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class SharedLibraryTest: public CppUnit::TestCase
{
public:
	SharedLibraryTest(const std::string& name);
	~SharedLibraryTest();

	void testSharedLibrary1();
	void testSharedLibrary2();
	void testSharedLibrary3();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
	static std::string getFullName(const std::string& libName);
};


#endif // SharedLibraryTest_INCLUDED
