module;

#define POCO_ENABLE_MODULES

#include "AtomicCounter.cpp"

export module poco.foundation:atomicCounter;


export namespace Poco
{
	using Poco::AtomicCounter;
}