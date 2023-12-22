//
// URIStreamOpenerTest.h
//
// Definition of the URIStreamOpenerTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef URIStreamOpenerTest_INCLUDED
#define URIStreamOpenerTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class URIStreamOpenerTest: public CppUnit::TestCase
{
public:
	URIStreamOpenerTest(const std::string& name);
	~URIStreamOpenerTest();

	void testStreamOpenerFile();
	void testStreamOpenerRelative();
	void testStreamOpenerURI();
	void testStreamOpenerURIResolve();
	void testStreamOpenerPath();
	void testStreamOpenerPathResolve();
	void testRegisterUnregister();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // URIStreamOpenerTest_INCLUDED
