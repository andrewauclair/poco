module;

#define POCO_ENABLE_MODULES

#include "Limit.cpp"

export module poco.data:Limit;

export namespace Poco::Data
{
    using Poco::Data::Limit;
}
