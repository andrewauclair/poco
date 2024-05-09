module;

#define POCO_ENABLE_MODULES

#include "VarVisitor.cpp"

export module poco.foundation:dynamicVarVisitor;

export namespace Poco
{
	namespace Dynamic
	{
		using Poco::Dynamic::Visitor;
	}
}
