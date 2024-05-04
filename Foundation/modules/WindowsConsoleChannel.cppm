module;

#define POCO_ENABLE_MODULES

#include "WindowsConsoleChannel.cpp"

export module poco.foundation:windowsConsoleChannel;


export namespace Poco
{
	using Poco::WindowsConsoleChannel;
	using Poco::WindowsColorConsoleChannel;
}
