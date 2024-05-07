module;

#define POCO_ENABLE_MODULES

#include "Poco/Dynamic/Array.h"

export module poco.foundation:dynamicArray;

export namespace Poco
{
	export namespace Dynamic
	{
		using Poco::Dynamic::Array;
	}
	using Poco::DynamicArray;
}
