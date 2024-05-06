module;

#define POCO_ENABLE_MODULES

#include "VarVisitor.cpp"

export module poco.foundation:dynamicVarVisitor;

export namespace Poco
{
export namespace Dynamic {
export using Poco::Dynamic::Visitor;
}
}
