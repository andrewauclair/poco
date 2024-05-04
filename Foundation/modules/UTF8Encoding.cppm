module;

#define POCO_ENABLE_MODULES

#include "UTF8Encoding.cpp"

export module poco.foundation:UTF8Encoding;


export namespace Poco
{
	using Poco::UTF8Encoding;
}
