module;

#define POCO_ENABLE_MODULES

#include "sql/Expr.cpp"

export module poco.data:Expr;

export namespace hsql
{
    using hsql::Expr;
}
