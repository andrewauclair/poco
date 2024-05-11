module;

#define POCO_ENABLE_MODULES

#include "Statement.cpp"

export module poco.data:Statement;

export namespace Poco::Data
{
    using Poco::Data::Statement;
}
