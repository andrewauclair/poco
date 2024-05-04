module;

#define POCO_ENABLE_MODULES

#include "PatternFormatter.cpp"

export module poco.foundation:patternFormatter;


export namespace Poco
{
	export using Poco::PatternFormatter;
}
