module;

#define POCO_ENABLE_MODULES

#include "Poco/Logger.h"

export module poco.foundation:logger;


export namespace Poco
{
	using Poco::Logger;
}
