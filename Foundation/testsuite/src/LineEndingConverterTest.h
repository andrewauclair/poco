//
// LineEndingConverterTest.h
//
// Definition of the LineEndingConverterTest class.
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef LineEndingConverterTest_INCLUDED
#define LineEndingConverterTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class LineEndingConverterTest: public CppUnit::TestCase
{
public:
	LineEndingConverterTest(const std::string& name);
	~LineEndingConverterTest();

	void testInputDosToUnix();
	void testInputUnixToDos();
	void testInputMacToUnix();
	void testInputRemove();
	void testOutputDosToUnix();
	void testOutputUnixToDos();
	void testOutputMacToUnix();
	void testOutputRemove();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // LineEndingConverterTest_INCLUDED
