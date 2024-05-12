module;

#define POCO_ENABLE_MODULES

#include "Poco/LogFile.h"

export module poco.foundation:logFile;


export namespace Poco
{
	using Poco::LogFile;
}
