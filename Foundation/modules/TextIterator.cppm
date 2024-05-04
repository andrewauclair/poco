module;

#define POCO_ENABLE_MODULES

#include "TextIterator.cpp"

export module poco.foundation:textIterator;


export namespace Poco
{
	using Poco::TextIterator;
}
