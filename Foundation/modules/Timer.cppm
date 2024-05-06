module;

#define POCO_ENABLE_MODULES

#include "Timer.cpp"

export module poco.foundation:timer;


export namespace Poco
{
	using Poco::Timer;
}
