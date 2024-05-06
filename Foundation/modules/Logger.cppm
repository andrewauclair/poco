module;

#define POCO_ENABLE_MODULES

#include "Logger.cpp"

export module poco.foundation:logger;


export namespace Poco
{
	export using Poco::Logger;
}
