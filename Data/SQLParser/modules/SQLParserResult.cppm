module;

#define POCO_ENABLE_MODULES

#include "SQLParserResult.cpp"

export module poco.data:SQLParserResult;

export namespace hsql
{
    using hsql::SQLParserResult;
}
