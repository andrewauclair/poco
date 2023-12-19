//
// TimedNotificationQueueTest.h
//
// Definition of the TimedNotificationQueueTest class.
//
// Copyright (c) 2009, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TimedNotificationQueueTest_INCLUDED
#define TimedNotificationQueueTest_INCLUDED


#include "CppUnit/CppAsserts.h"
#include "CppUnit/CppTestMacros.h"

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#include "Poco/TimedNotificationQueue.h"
#include "Poco/Mutex.h"
#include <set>
#endif

class TimedNotificationQueueTest: public CppUnit::TestCase
{
public:
	TimedNotificationQueueTest(const std::string& name);
	~TimedNotificationQueueTest();

	void testDequeue();
	void testDequeueNext();
	void testWaitDequeue();
	void testWaitDequeueTimeout();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

protected:
	void work();

private:
};


#endif // TimedNotificationQueueTest_INCLUDED
