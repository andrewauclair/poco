module;

#define POCO_ENABLE_MODULES

#include "Poco/LoggingRegistry.h"

export module poco.foundation:loggingRegistry;


export namespace Poco
{
	using Poco::LoggingRegistry;
}
