module;

#define POCO_ENABLE_MODULES

#include "Poco/ThreadPool.h"

export module poco.foundation:threadPool;

export namespace Poco
{
	using Poco::ThreadPool;
}
