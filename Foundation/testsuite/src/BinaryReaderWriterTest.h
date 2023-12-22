//
// BinaryReaderWriterTest.h
//
// Definition of the BinaryReaderWriterTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef BinaryReaderWriterTest_INCLUDED
#define BinaryReaderWriterTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#include "Poco/BinaryReader.h"
#include "Poco/BinaryWriter.h"
#endif


class BinaryReaderWriterTest: public CppUnit::TestCase
{
public:
	BinaryReaderWriterTest(const std::string& name);
	~BinaryReaderWriterTest();

	void testNative();
	void testBigEndian();
	void testLittleEndian();
	void testWrappers();
	void write(Poco::BinaryWriter& writer);
	void read(Poco::BinaryReader& reader);

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // BinaryReaderWriterTest_INCLUDED
