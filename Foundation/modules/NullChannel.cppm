module;

#define POCO_ENABLE_MODULES

#include "NullChannel.cpp"

export module poco.foundation:nullChannel;


export namespace Poco
{
	export using Poco::NullChannel;
}
