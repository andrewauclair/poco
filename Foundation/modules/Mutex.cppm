module;

#include "Poco/ModuleIncludes.h"

#define POCO_ENABLE_MODULES

export module PocoFoundation:Mutex;

#include "Mutex.cpp"
