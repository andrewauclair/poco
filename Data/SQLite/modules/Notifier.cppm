module;

#define POCO_ENABLE_MODULES

#include "Notifier.cpp"

export module poco.data.sqlite:Notifier;

export namespace Poco::Data::SQLite
{
    using Poco::Data::SQLite::Notifier;
}
