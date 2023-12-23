module;

#undef CppUnit_EXPORTS

#include "CppUnit/CppUnit.h"
#include "CppUnit/CppUnitException.h"
#include "CppUnit/estring.h"
#include "CppUnit/Guards.h"
#include "CppUnit/Orthodox.h"
#include "CppUnit/RepeatedTest.h"
#include "CppUnit/Test.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestCase.h"
#include "CppUnit/TestDecorator.h"
#include "CppUnit/TestFailure.h"
#include "CppUnit/TestResult.h"
#include "CppUnit/TestRunner.h"
#include "CppUnit/TestSetup.h"
#include "CppUnit/TestSuite.h"
#include "CppUnit/TextTestResult.h"

export module poco.cppunit;

namespace CppUnit
{
	export using CppUnit::Test;
	export using CppUnit::TestCaller;
	export using CppUnit::TestCase;
	export using CppUnit::TestDecorator;
	export using CppUnit::TestFailure;
	export using CppUnit::TestResult;
	export using CppUnit::TestRunner;
	export using CppUnit::TestSetup;
	export using CppUnit::TestSuite;
}