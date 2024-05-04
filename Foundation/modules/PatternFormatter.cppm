module;

#define POCO_ENABLE_MODULES

#include "PatternFormatter.cpp"

export module poco.foundation:patternFormatter;


export namespace Poco
{
	using Poco::PatternFormatter;
}
