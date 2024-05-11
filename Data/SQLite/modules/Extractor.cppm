module;

#define POCO_ENABLE_MODULES

#include "Extractor.cpp"

export module poco.data.sqlite:Extractor;

export namespace Poco::Data::SQLite
{
    using Poco::Data::SQLite::Extractor;
}
