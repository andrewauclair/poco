module;

#define POCO_ENABLE_MODULES

#include "SQLiteException.cpp"

export module poco.data.sqlite:SQLiteException;

export namespace Poco::Data::SQLite
{
    using Poco::Data::SQLite::SQLiteException;
}
