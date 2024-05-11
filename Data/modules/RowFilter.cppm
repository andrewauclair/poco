module;

#define POCO_ENABLE_MODULES

#include "RowFilter.cpp"

export module poco.data:RowFilter;

export namespace Poco::Data
{
    using Poco::Data::RowFilter;
}
