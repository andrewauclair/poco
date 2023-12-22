//
// TeeStreamTest.h
//
// Definition of the TeeStreamTest class.
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TeeStreamTest_INCLUDED
#define TeeStreamTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class TeeStreamTest: public CppUnit::TestCase
{
public:
	TeeStreamTest(const std::string& name);
	~TeeStreamTest();

	void testTeeInputStream();
	void testTeeOutputStream();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // TeeStreamTest_INCLUDED
