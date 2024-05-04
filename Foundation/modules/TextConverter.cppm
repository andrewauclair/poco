module;

#define POCO_ENABLE_MODULES

#include "TextConverter.cpp"

export module poco.foundation:textConverter;


export namespace Poco
{
	using Poco::TextConverter;
}
