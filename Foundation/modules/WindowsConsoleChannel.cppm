module;

#define POCO_ENABLE_MODULES

#include "Poco/WindowsConsoleChannel.h"

export module poco.foundation:windowsConsoleChannel;


export namespace Poco
{
	using Poco::WindowsConsoleChannel;
	using Poco::WindowsColorConsoleChannel;
}
