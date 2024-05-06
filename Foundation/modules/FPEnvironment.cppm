module;

#define POCO_ENABLE_MODULES

#include "FPEnvironment.cpp"

export module poco.foundation:fpEnvironment;


export namespace Poco
{
	using Poco::FPEnvironment;
}
