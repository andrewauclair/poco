module;

#define POCO_ENABLE_MODULES

#include "NumberFormatter.cpp"

export module poco.foundation:numberFormatter;


export namespace Poco
{
	export using Poco::NumberFormatter;
}
