//
// SessionPoolTest.h
//
// Definition of the SessionPoolTest class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef SessionPoolTest_INCLUDED
#define SessionPoolTest_INCLUDED

#if !defined(POCO_ALREADY_IMPORTED_MODULES)
#include "Poco/Data/Data.h"
#include "CppUnit/TestCase.h"
#else
#include <chrono> // why the hell do we need to include <chrono> here to satisfy <thread>?
#include <string>
#endif

class SessionPoolTest: public CppUnit::TestCase
{
public:
	SessionPoolTest(const std::string& name);
	~SessionPoolTest();

	void testSessionPool();
	void testSessionPoolContainer();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // SessionPoolTest_INCLUDED
