module;

#define POCO_ENABLE_MODULES

#include "Query.cpp"

export module poco.JSON:Query;

export namespace Poco::JSON
{
    using Poco::JSON::Query;
}
