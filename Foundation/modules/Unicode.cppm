module;

#define POCO_ENABLE_MODULES

#include "Unicode.cpp"

export module poco.foundation:unicode;


export namespace Poco
{
	using Poco::Unicode;
}
