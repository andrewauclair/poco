module;

#define POCO_ENABLE_MODULES

#include "RowFormatter.cpp"

export module poco.data:RowFormatter;

export namespace Poco::Data
{
    using Poco::Data::RowFormatter;
}
