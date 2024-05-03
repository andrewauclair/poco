module;

#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <type_traits>

#if defined(POCO_OS_FAMILY_WINDOWS)
#include "Poco/UnWindows.h"
#endif

export module PocoFoundation;

export import :Exception;
export import :Mutex;
export import :Timestamp;
export import :Timespan;