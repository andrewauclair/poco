#include "ActiveDispatcherTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include <iostream>

import poco.foundation;


using Poco::ActiveDispatcher;
using Poco::ActiveMethod;
using Poco::ActiveResult;
using Poco::ActiveStarter;
using Poco::Thread;
using Poco::Event;
using Poco::Exception;
using Poco::Environment;

//namespace
//{
//	class ActiveObject : public ActiveDispatcher
//	{
//	public:
//		ActiveObject() :
//			testMethod(this, &ActiveObject::testMethodImpl),
//			testVoid(this, &ActiveObject::testVoidImpl),
//			testVoidInOut(this, &ActiveObject::testVoidInOutImpl),
//			testVoidIn(this, &ActiveObject::testVoidInImpl)
//		{
//		}
//
//		~ActiveObject()
//		{
//		}
//
//		ActiveMethod<int, int, ActiveObject, ActiveStarter<ActiveDispatcher> > testMethod;
//
//		ActiveMethod<void, int, ActiveObject, ActiveStarter<ActiveDispatcher> > testVoid;
//
//		ActiveMethod<void, void, ActiveObject, ActiveStarter<ActiveDispatcher> > testVoidInOut;
//
//		ActiveMethod<int, void, ActiveObject, ActiveStarter<ActiveDispatcher> > testVoidIn;
//
//		void cont()
//		{
//			_continue.set();
//		}
//
//	protected:
//		int testMethodImpl(const int& n)
//		{
//			if (n == 100) throw Exception("n == 100");
//			_continue.wait();
//			return n;
//		}
//
//		void testVoidImpl(const int& n)
//		{
//			if (n == 100) throw Exception("n == 100");
//			_continue.wait();
//		}
//
//		void testVoidInOutImpl()
//		{
//			_continue.wait();
//		}
//
//		int testVoidInImpl()
//		{
//			_continue.wait();
//			return 123;
//		}
//
//	private:
//		Event _continue;
//	};
//}

void test()
{
	Poco::Event e;
	e.set();
	e.wait();
	//ActiveResult<int> a = nullptr;
}