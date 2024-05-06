module;

#define POCO_ENABLE_MODULES

#include "PIDFile.cpp"

export module poco.foundation:PIDFile;


export namespace Poco
{
	using Poco::PIDFile;
}
