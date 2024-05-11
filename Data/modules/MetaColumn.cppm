module;

#define POCO_ENABLE_MODULES

#include "MetaColumn.cpp"

export module poco.data:MetaColumn;

export namespace Poco::Data
{
    using Poco::Data::MetaColumn;
}
