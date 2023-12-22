//
// ChannelTest.h
//
// Definition of the ChannelTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ChannelTest_INCLUDED
#define ChannelTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class ChannelTest : public CppUnit::TestCase
{
public:
	ChannelTest(const std::string& name);
	~ChannelTest();

	void testSplitter();
	void testSplitterAddSameChannelTwice();
	void testAsync();
	void testFormatting();
	void testConsole();
	void testStream();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // ChannelTest_INCLUDED
