module;

#define POCO_ENABLE_MODULES

#include "UTF32Encoding.cpp"

export module poco.foundation:UTF32Encoding;


export namespace Poco
{
	export using Poco::UTF32Encoding;
}
