//
// AutoPtrTest.h
//
// Definition of the AutoPtrTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef AutoPtrTest_INCLUDED
#define AutoPtrTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class AutoPtrTest: public CppUnit::TestCase
{
public:
	AutoPtrTest(const std::string& name);
	~AutoPtrTest();

	void testAutoPtr();
	void testOps();
	void testMakeAuto();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // AutoPtrTest_INCLUDED
