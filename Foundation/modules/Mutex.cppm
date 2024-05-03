module;

#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <type_traits>

#include "Poco/UnWindows.h"

#define POCO_ENABLE_MODULES

export module PocoFoundation:Mutex;

#include "Mutex.cpp"
