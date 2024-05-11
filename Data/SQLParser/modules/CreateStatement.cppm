module;

#define POCO_ENABLE_MODULES

#include "sql/CreateStatement.cpp"

export module poco.data:CreateStatement;

export namespace hsql
{
    using hsql::CreateStatement;
}
