module;

#define POCO_ENABLE_MODULES

#include "Timespan.cpp"

export module poco.foundation:timespan;

export namespace Poco
{
	using Poco::Timespan;
}
