module;

#define POCO_ENABLE_MODULES

#include "Stopwatch.cpp"

export module poco.foundation:stopwatch;


export namespace Poco
{
	using Poco::Stopwatch;
}
