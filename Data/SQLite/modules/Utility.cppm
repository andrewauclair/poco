module;

#define POCO_ENABLE_MODULES

#include "Utility.cpp"

export module poco.data.sqlite:Utility;

export namespace Poco::Data::SQLite
{
    using Poco::Data::SQLite::Utility;
}
