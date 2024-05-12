module;

#define POCO_ENABLE_MODULES

#include "Poco/Dynamic/Var.h"

export module poco.foundation:dynamicVar;

export namespace Poco
{
	namespace Dynamic
	{
		using Poco::Dynamic::Var;
	}
	using Poco::DynamicAny;
}
