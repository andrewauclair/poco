//
// TestCaller.h
//


#ifndef CppUnit_TestCaller_INCLUDED
#define CppUnit_TestCaller_INCLUDED


#include "CppUnit/CppUnit.h"
#include "Guards.h"
#include "TestCase.h"
#include <memory>


namespace CppUnit {


/*
 * A test caller provides access to a test case method
 * on a test case class.  Test callers are useful when
 * you want to run an individual test or add it to a
 * suite.
 *
 * Here is an example:
 *
 * class MathTest : public TestCase {
 *         ...
 *     public:
 *         void         setUp ();
 *         void         tearDown ();
 *
 *         void         testAdd ();
 *         void         testSubtract ();
 * };
 *
 * Test *MathTest::suite () {
 *     TestSuite *suite = new TestSuite;
 *
 *     suite->addTest (new TestCaller<MathTest> ("testAdd", testAdd));
 *     return suite;
 * }
 *
 * You can use a TestCaller to bind any test method on a TestCase
 * class, as long as it accepts void and returns void.
 *
 * See TestCase
 */
POCO_MODULES_EXPORT_CppUnit 
template <class Fixture>
class TestCaller: public TestCase
{
	REFERENCEOBJECT (TestCaller)

	typedef void (Fixture::*TestMethod)();

public:
	TestCaller(const std::string& name, TestMethod test, Test::Type testType = Test::Normal):
		TestCase(name, testType),
		_test(test),
		_fixture(new Fixture(name))
	{
	}

protected:
	void runTest()
	{
		(_fixture.get()->*_test)();
	}

	void setUp()
	{
		if (!setup().empty())
			_fixture.get()->addSetup(setup());
		_fixture.get()->setUp();
	}

	void tearDown()
	{
		_fixture.get()->tearDown();
	}

private:
	TestMethod             _test;
	std::unique_ptr<Fixture> _fixture;
};


} // namespace CppUnit


#include"CppUnit/Asserts.h"

#endif // CppUnit_TestCaller_INCLUDED
