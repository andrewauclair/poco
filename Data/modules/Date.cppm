module;

#define POCO_ENABLE_MODULES

#include "Date.cpp"

export module poco.data:Date;

export namespace Poco::Data
{
    using Poco::Data::Date;
}
