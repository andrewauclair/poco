module;

#define POCO_ENABLE_MODULES

#include "ArchiveStrategy.cpp"

export module poco.data:ArchiveStrategy;

export namespace Poco::Data
{
    using Poco::Data::ArchiveStrategy;
}
