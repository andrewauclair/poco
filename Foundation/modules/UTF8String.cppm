module;

#define POCO_ENABLE_MODULES

#include "UTF8String.cpp"

export module poco.foundation:UTF8String;


export namespace Poco
{
	using Poco::UTF8;
}
