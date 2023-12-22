//
// ManifestTest.h
//
// Definition of the ManifestTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ManifestTest_INCLUDED
#define ManifestTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class ManifestTest: public CppUnit::TestCase
{
public:
	ManifestTest(const std::string& name);
	~ManifestTest();

	void testManifest();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // ManifestTest_INCLUDED
