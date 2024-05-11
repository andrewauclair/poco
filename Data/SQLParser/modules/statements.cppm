module;

#define POCO_ENABLE_MODULES

#include "sql/statements.cpp"

export module poco.data:statements;

export namespace hsql
{
    using hsql::AlterStatement;
    using hsql::CreateStatement;
    using hsql::DeleteStatement;
    using hsql::DropStatement;
    using hsql::ExecuteStatement;
    using hsql::ExportStatement;
    using hsql::ImportStatement;
    using hsql::InsertStatement;
    using hsql::PrepareStatement;
    using hsql::SelectStatement;
    using hsql::ShowStatement;
    using hsql::TransactionStatement;
    using hsql::UpdateStatement;
}
