module;

#define POCO_ENABLE_MODULES

#include "Poco/Environment.h"

export module poco.foundation:environment;

export namespace Poco
{
	using Poco::Environment;
}
