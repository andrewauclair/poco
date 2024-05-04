module;

#define POCO_ENABLE_MODULES

#include "LineEndingConverter.cpp"

export module poco.foundation:lineEndingConverter;


export namespace Poco
{
	export using Poco::LineEnding;
	export using Poco::LineEndingConverterIOS;
	export using Poco::InputLineEndingConverter;
	export using Poco::OutputLineEndingConverter;
}
