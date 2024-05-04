module;

#define POCO_ENABLE_MODULES

#include "Process.cpp"

export module poco.foundation:process;


export namespace Poco
{
	using Poco::Process;
}
