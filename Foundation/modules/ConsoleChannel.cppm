module;

#define POCO_ENABLE_MODULES

#include "ConsoleChannel.cpp"

export module poco.foundation:consoleChannel;


export namespace Poco
{
	using Poco::ConsoleChannel;
}
