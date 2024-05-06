module;

#define POCO_ENABLE_MODULES

#include "NestedDiagnosticContext.cpp"

export module poco.foundation:NestedDiagnosticContext;

export namespace Poco
{
    using Poco::NestedDiagnosticContext;
}
