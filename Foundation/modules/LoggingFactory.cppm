module;

#define POCO_ENABLE_MODULES

#include "Poco/LoggingFactory.h"

export module poco.foundation:loggingFactory;


export namespace Poco
{
	using Poco::LoggingFactory;
}
