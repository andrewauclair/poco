module;

#define POCO_ENABLE_MODULES

#include "Mutex.cpp"

export module poco.foundation:mutex;

import :exception;

export namespace Poco
{
	using Poco::Mutex;
}
