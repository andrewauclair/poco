module;

#define POCO_ENABLE_MODULES

#include "Poco/Mutex.h"

export module poco.foundation:mutex;

import :exception;

export namespace Poco
{
	using Poco::Mutex;
}
