module;

#define POCO_ENABLE_MODULES

#include "DateTimeFormat.cpp"

export module poco.foundation:dateTimeFormat;


export namespace Poco
{
	using Poco::DateTimeFormat;
}
