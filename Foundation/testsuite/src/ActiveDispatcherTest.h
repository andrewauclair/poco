//
// ActiveDispatcherTest.h
//
// Definition of the ActiveDispatcherTest class.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef ActiveDispatcherTest_INCLUDED
#define ActiveDispatcherTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#endif

class ActiveDispatcherTest: public CppUnit::TestCase
{
public:
	ActiveDispatcherTest(const std::string& name);
	~ActiveDispatcherTest();

	void testWait();
	void testWaitInterval();
	void testTryWait();
	void testFailure();
	void testVoid();
	void testVoidIn();
	void testVoidInOut();
	void testActiveDispatcher();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
};


#endif // ActiveDispatcherTest_INCLUDED
