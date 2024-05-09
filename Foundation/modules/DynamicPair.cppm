module;

#define POCO_ENABLE_MODULES

#include "Poco/Dynamic/Pair.h"

export module poco.foundation:dynamicPair;

export namespace Poco
{
	namespace Dynamic
	{
		using Poco::Dynamic::Pair;
	}
}
