module;

#define POCO_ENABLE_MODULES

#include "Poco/Dynamic/VarHolder.h"

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
