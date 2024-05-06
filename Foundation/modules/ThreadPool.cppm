module;

#define POCO_ENABLE_MODULES

#include "ThreadPool.cpp"

export module poco.foundation:threadPool;

export namespace Poco
{
	using Poco::ThreadPool;
}
