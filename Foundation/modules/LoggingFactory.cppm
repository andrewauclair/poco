module;

#define POCO_ENABLE_MODULES

#include "LoggingFactory.cpp"

export module poco.foundation:loggingFactory;


export namespace Poco
{
	export using Poco::LoggingFactory;
}
