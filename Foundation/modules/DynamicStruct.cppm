module;

#define POCO_ENABLE_MODULES

#include "Poco/Dynamic/Struct.h"

export module poco.foundation:dynamicStruct;

export namespace Poco
{
	export namespace Dynamic
	{
		using Poco::Dynamic::Struct;
	}
	using Poco::DynamicStruct;
	using Poco::OrderedDynamicStruct;
}
