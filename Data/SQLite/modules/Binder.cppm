module;

#define POCO_ENABLE_MODULES

#include "Binder.cpp"

export module poco.data.sqlite:Binder;

export namespace Poco::Data::SQLite
{
    using Poco::Data::SQLite::Binder;
}
