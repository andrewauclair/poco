//
// TimerTest.h
//
// Definition of the TimerTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TimerTest_INCLUDED
#define TimerTest_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#include "Poco/Timer.h"
#include "Poco/Event.h"
#endif


class TimerTest: public CppUnit::TestCase
{
public:
	TimerTest(const std::string& name);
	~TimerTest();

	void testTimer();
	void testDuplicateStop();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

protected:
	void onTimer(Poco::Timer& t);

private:
	Poco::Event _event;
};


#endif // TimerTest_INCLUDED
