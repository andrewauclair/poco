module;

#define POCO_ENABLE_MODULES

#include "Poco/Clock.h"

export module poco.foundation:clock;

export namespace Poco
{
	using Poco::Clock;
}
