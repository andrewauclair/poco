module;

#define POCO_ENABLE_MODULES

#include "Debugger.cpp"

export module poco.foundation:debugger;


export namespace Poco
{
	using Poco::Debugger;
}