module;

#define POCO_ENABLE_MODULES

#include "sql/SQLStatement.cpp"

export module poco.data:SQLStatement;

export namespace hsql
{
    using hsql::SQLStatement;
}
