module;

#define POCO_ENABLE_MODULES

#include "Format.cpp"

export module poco.foundation:format;


export namespace Poco
{
	using Poco::format;
}
