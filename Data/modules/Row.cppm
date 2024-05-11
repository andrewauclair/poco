module;

#define POCO_ENABLE_MODULES

#include "Row.cpp"

export module poco.data:Row;

export namespace Poco::Data
{
    using Poco::Data::Row;
}
