module;

#define POCO_ENABLE_MODULES

#include "RowIterator.cpp"

export module poco.data:RowIterator;

export namespace Poco::Data
{
    using Poco::Data::RowIterator;
}
