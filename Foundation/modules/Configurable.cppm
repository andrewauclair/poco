module;

#define POCO_ENABLE_MODULES

#include "Configurable.cpp"

export module poco.foundation:configurable;


export namespace Poco
{
	using Poco::Configurable;
}
