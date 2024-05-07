module;

#define POCO_ENABLE_MODULES

#include "Var.cpp"

export module poco.foundation:dynamicVar;

export namespace Poco
{
	export namespace Dynamic
	{
		using Poco::Dynamic::Var;
	}
	using Poco::DynamicAny;
}
