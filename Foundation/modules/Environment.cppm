module;

#define POCO_ENABLE_MODULES

#include "Environment.cpp"

export module poco.foundation:environment;

export namespace Poco
{
	export using Poco::Environment;
}
