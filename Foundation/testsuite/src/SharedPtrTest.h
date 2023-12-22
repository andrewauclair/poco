//
// SharedPtrTest.h
//
// Definition of the SharedPtrTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef SharedPtrTest_INCLUDED
#define SharedPtrTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class SharedPtrTest: public CppUnit::TestCase
{
public:
	SharedPtrTest(const std::string& name);
	~SharedPtrTest();

	void testSharedPtr();

	void testImplicitCast();
	void testExplicitCast();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // SharedPtrTest_INCLUDED
