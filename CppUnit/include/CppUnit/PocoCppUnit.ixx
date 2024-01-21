module;

#include <functional>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

// make sure the module imports the classes. unsure on this.
#undef CppUnit_EXPORTS

// setup macros for exporting classes for the module
#define POCO_MODULES_EXPORT_CppUnit export
#define POCO_MODULES_EXPORT_BEGIN_CppUnit export {
#define POCO_MODULES_EXPORT_END_CppUnit }

// needs to be here to potentially pull Windows.h
#if defined(_WIN32)
#include "Poco/UnWindows.h"
#endif

export module PocoCppUnit;

#include "RepeatedTest.h"
#include "Test.h"
#include "TestCaller.h"
#include "TestCase.h"
#include "TestDecorator.h"
#include "TestFailure.h"
#include "TestResult.h"
#include "TestRunner.h"
#include "TestSetup.h"
#include "TestSuite.h"
#include "TextTestResult.h"
