module;

#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <type_traits>

#if defined(POCO_OS_FAMILY_WINDOWS)
#include "Poco/UnWindows.h"
#endif

#define POCO_ENABLE_MODULES

export module PocoFoundation:Timestamp;

#include "Timestamp.cpp"
