module;

#define POCO_ENABLE_MODULES

#include "SQLParser.cpp"

export module poco.data:SQLParser;

export namespace hsql
{
    using hsql::SQLParser;
}
