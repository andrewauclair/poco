module;

#define POCO_ENABLE_MODULES

#include "UnicodeConverter.cpp"

export module poco.foundation:unicodeConverter;


export namespace Poco
{
	export using Poco::UnicodeConverter;
}
