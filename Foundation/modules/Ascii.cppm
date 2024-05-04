module;

#define POCO_ENABLE_MODULES

#include "Ascii.cpp"

export module poco.foundation:ascii;


export namespace Poco
{
	using Poco::Ascii;
}
