module;

#define POCO_ENABLE_MODULES

#include "Poco/LineEndingConverter.h"

export module poco.foundation:lineEndingConverter;


export namespace Poco
{
	using Poco::LineEnding;
	using Poco::LineEndingConverterIOS;
	using Poco::InputLineEndingConverter;
	using Poco::OutputLineEndingConverter;
}
