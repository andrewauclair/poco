module;

#define POCO_ENABLE_MODULES

#include "SQLiteStatementImpl.cpp"

export module poco.data.sqlite:SQLiteStatementImpl;

export namespace Poco::Data::SQLite
{
    using Poco::Data::SQLite::SQLiteStatementImpl;
}
