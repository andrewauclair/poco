module;

#define POCO_ENABLE_MODULES

#include "AsyncChannel.cpp"

export module poco.foundation:asyncChannel;


export namespace Poco
{
	using Poco::AsyncChannel;
}
