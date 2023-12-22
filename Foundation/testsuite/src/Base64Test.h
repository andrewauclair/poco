//
// Base64Test.h
//
// Definition of the Base64Test class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Base64Test_INCLUDED
#define Base64Test_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class Base64Test: public CppUnit::TestCase
{
public:
	Base64Test(const std::string& name);
	~Base64Test();

	void testEncoder();
	void testEncoderURL();
	void testEncoderNoPadding();
	void testDecoder();
	void testDecoderURL();
	void testDecoderNoPadding();
	void testEncodeDecode();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // Base64Test_INCLUDED
