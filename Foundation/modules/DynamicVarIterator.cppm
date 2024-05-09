module;

#define POCO_ENABLE_MODULES

#include "VarIterator.cpp"

export module poco.foundation:dynamicVarIterator;

export namespace Poco
{
	namespace Dynamic
	{
		using Poco::Dynamic::VarIterator;
	}
}
