module;

#define POCO_ENABLE_MODULES

#include "DateTimeParser.cpp"

export module poco.foundation:dateTimeParser;


export namespace Poco
{
	export using Poco::DateTimeParser;
}
