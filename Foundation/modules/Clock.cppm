module;

#define POCO_ENABLE_MODULES

#include "Clock.cpp"

export module poco.foundation:clock;

export namespace Poco
{
	using Poco::Clock;
}
