module;

#define POCO_ENABLE_MODULES

#include "Poco/Dynamic/VarVisitor.h"

export module poco.foundation:dynamicVarVisitor;

export namespace Poco
{
	namespace Dynamic
	{
		using Poco::Dynamic::Visitor;
	}
}
