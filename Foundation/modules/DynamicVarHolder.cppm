module;

#define POCO_ENABLE_MODULES

#include "VarHolder.cpp"

export module poco.foundation:dynamicVarHolder;

export namespace Poco
{
	namespace Dynamic
	{
		using Poco::Dynamic::VarHolder;
		using Poco::Dynamic::VarHolderImpl;
		using Poco::Dynamic::Array;
	}
}
