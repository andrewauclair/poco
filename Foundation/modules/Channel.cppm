module;

#define POCO_ENABLE_MODULES

#include "Channel.cpp"

export module poco.foundation:channel;


export namespace Poco
{
	export using Poco::Channel;
}
