module;

#define POCO_ENABLE_MODULES

#include "TextEncoding.cpp"

export module poco.foundation:textEncoding;


export namespace Poco
{
	using Poco::TextEncoding;
}
