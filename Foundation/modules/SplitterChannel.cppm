module;

#define POCO_ENABLE_MODULES

#include "SplitterChannel.cpp"

export module poco.foundation:splitterChannel;


export namespace Poco
{
	export using Poco::SplitterChannel;
}
