module;

#define POCO_ENABLE_MODULES

#include "EventLogChannel.cpp"

export module poco.foundation:eventLogChannel;


export namespace Poco
{
	using Poco::EventLogChannel;
}
