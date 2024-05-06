module;

#define POCO_ENABLE_MODULES

#include "MemoryPool.cpp"

export module poco.foundation:memoryPool;


export namespace Poco
{
	using Poco::MemoryPool;
}
