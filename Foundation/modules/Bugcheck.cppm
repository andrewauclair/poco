module;

#define POCO_ENABLE_MODULES

#include "Bugcheck.cpp"

export module poco.foundation:bugcheck;


export namespace Poco
{
	export using Poco::Bugcheck;
}
