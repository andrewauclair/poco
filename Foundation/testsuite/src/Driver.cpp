//
// Driver.cpp
//
// Console-based test driver.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "CppUnit/TestRunner.h"
#include "FoundationTestSuite.h"

#if defined(POCO_MODULES)
import std;
import poco.cppunit;
import poco.foundation;
#endif

CppUnitMain(FoundationTestSuite)
