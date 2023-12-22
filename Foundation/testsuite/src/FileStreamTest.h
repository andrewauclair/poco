//
// FileStreamTest.h
//
// Definition of the FileStreamTest class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef FileStreamTest_INCLUDED
#define FileStreamTest_INCLUDED


#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif


class FileStreamTest: public CppUnit::TestCase
{
public:
	FileStreamTest(const std::string& name);
	~FileStreamTest();

	void testRead();
	void testWrite();
	void testReadWrite();
	void testOpen();
	void testOpenModeIn();
	void testOpenModeOut();
	void testOpenModeTrunc();
	void testOpenModeAte();
	void testOpenModeApp();
	void testSeek();
	void testMultiOpen();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // FileStreamTest_INCLUDED
