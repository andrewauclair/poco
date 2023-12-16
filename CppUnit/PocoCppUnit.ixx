module;

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

export module PocoCppUnit;

namespace CppUnit
{
	export using CppUnit::TestCase;
}