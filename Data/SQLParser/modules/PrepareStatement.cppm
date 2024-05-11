module;

#define POCO_ENABLE_MODULES

#include "sql/PrepareStatement.cpp"

export module poco.data:PrepareStatement;

export namespace hsql
{
    using hsql::PrepareStatement;
}
