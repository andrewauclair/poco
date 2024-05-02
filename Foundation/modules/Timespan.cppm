module;

#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <type_traits>
#include <windows.h>

#define POCO_ENABLE_MODULES

export module PocoFoundation:Timespan;

#include "Timespan.cpp"
