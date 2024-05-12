module;

#define POCO_ENABLE_MODULES

#include "Poco/AtomicCounter.h"

export module poco.foundation:atomicCounter;


export namespace Poco
{
	using Poco::AtomicCounter;
}
