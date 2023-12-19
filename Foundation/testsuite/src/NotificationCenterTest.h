//
// NotificationCenterTest.h
//
// Definition of the NotificationCenterTest class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef NotificationCenterTest_INCLUDED
#define NotificationCenterTest_INCLUDED

#include "CppUnit/CppAsserts.h"
#include "CppUnit/CppTestMacros.h"

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#else
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#include "Poco/Notification.h"
#include "Poco/AutoPtr.h"

#include <set>
#endif

class TestNotification;


class NotificationCenterTest: public CppUnit::TestCase
{
public:
	NotificationCenterTest(const std::string& name);
	~NotificationCenterTest();

	void test1();
	void test2();
	void test3();
	void test4();
	void test5();
	void testAuto();
	void testDefaultCenter();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

protected:
	void handle1(Poco::Notification* pNf);
	void handle2(Poco::Notification* pNf);
	void handle3(Poco::Notification* pNf);
	void handleTest(TestNotification* pNf);
	void handleAuto(const Poco::AutoPtr<Poco::Notification>& pNf);

private:
	std::set<std::string> _set;
};


#endif // NotificationCenterTest_INCLUDED
