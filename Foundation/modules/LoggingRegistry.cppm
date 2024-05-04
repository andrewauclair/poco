module;

#define POCO_ENABLE_MODULES

#include "LoggingRegistry.cpp"

export module poco.foundation:loggingRegistry;


export namespace Poco
{
	export using Poco::LoggingRegistry;
}
