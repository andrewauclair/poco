module;

#define POCO_ENABLE_MODULES

#include "Poco/NullChannel.h"

export module poco.foundation:nullChannel;


export namespace Poco
{
	using Poco::NullChannel;
}
