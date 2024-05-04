module;

#define POCO_ENABLE_MODULES

#include "NumberParser.cpp"

export module poco.foundation:numberParser;


export namespace Poco
{
	export using Poco::NumberParser;
}
