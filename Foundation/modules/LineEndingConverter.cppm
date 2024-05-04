module;

#define POCO_ENABLE_MODULES

#include "LineEndingConverter.cpp"

export module poco.foundation:lineEndingConverter;


export namespace Poco
{
	using Poco::LineEnding;
	using Poco::LineEndingConverterIOS;
	using Poco::InputLineEndingConverter;
	using Poco::OutputLineEndingConverter;
}
