module;

#define POCO_ENABLE_MODULES

#include "DateTimeFormatter.cpp"

export module poco.foundation:dateTimeFormatter;


export namespace Poco
{
	using Poco::DateTimeFormatter;
}