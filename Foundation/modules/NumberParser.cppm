module;

#define POCO_ENABLE_MODULES

#include "NumberParser.cpp"

export module poco.foundation:numberParser;


export namespace Poco
{
	using Poco::NumberParser;
}
