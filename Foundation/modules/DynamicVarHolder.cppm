module;

#define POCO_ENABLE_MODULES

#include "VarHolder.cpp"

export module poco.foundation:dynamicVarHolder;

export namespace Poco
{
export namespace Dynamic {
	export using Poco::Dynamic::VarHolder;
	export using Poco::Dynamic::VarHolderImpl;
	export using Poco::Dynamic::Array;
}
}
