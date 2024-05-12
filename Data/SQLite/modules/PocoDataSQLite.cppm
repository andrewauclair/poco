module;

#include "Poco/Data/SQLite/SQLiteException.h"
#include "Poco/Data/SQLite/Binder.h"
#include "Poco/Data/SQLite/Notifier.h"
#include "Poco/Data/SQLite/Extractor.h"
#include "Poco/Data/SQLite/SessionImpl.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/SQLite/SQLiteStatementImpl.h"
#include "Poco/Data/SQLite/Utility.h"

export module poco.data.sqlite;

export namespace Poco::Data
{
    using Poco::Data::SessionImpl;
    using Poco::Data::Connector;

    namespace SQLite
    {
        using Poco::Data::SQLite::SQLiteException;
        using Poco::Data::SQLite::Binder;
        using Poco::Data::SQLite::Notifier;
        using Poco::Data::SQLite::Extractor;
        using Poco::Data::SQLite::SQLiteStatementImpl;
        using Poco::Data::SQLite::Utility;
    }
}
