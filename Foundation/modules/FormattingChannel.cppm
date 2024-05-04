module;

#define POCO_ENABLE_MODULES

#include "FormattingChannel.cpp"

export module poco.foundation:formattingChannel;


export namespace Poco
{
	export using Poco::FormattingChannel;
}
