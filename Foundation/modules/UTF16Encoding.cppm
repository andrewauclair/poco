module;

#define POCO_ENABLE_MODULES

#include "UTF16Encoding.cpp"

export module poco.foundation:UTF16Encoding;


export namespace Poco
{
	export using Poco::UTF16Encoding;
}
