module;

#define POCO_ENABLE_MODULES

#include "Var.cpp"

export module poco.foundation:dynamicVar;

export namespace Poco::Dynamic
{
	export using Poco::Dynamic::Var;
}
