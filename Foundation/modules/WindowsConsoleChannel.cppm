module;

#define POCO_ENABLE_MODULES

#include "WindowsConsoleChannel.cpp"

export module poco.foundation:windowsConsoleChannel;


export namespace Poco
{
	export using Poco::WindowsConsoleChannel;
	export using Poco::WindowsColorConsoleChannel;
}
