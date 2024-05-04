module;

#define POCO_ENABLE_MODULES

#include "EventChannel.cpp"

export module poco.foundation:eventChannel;


export namespace Poco
{
	export using Poco::EventChannel;
}
