module;

#define POCO_ENABLE_MODULES

#include "LogFile.cpp"

export module poco.foundation:logFile;


export namespace Poco
{
	using Poco::LogFile;
}
