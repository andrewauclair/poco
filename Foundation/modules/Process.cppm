module;

#define POCO_ENABLE_MODULES

#include "Poco/Process.h"

export module poco.foundation:process;


export namespace Poco
{
	using Poco::Process;
}
