module;

#define POCO_ENABLE_MODULES

#include "Array.cpp"

export module poco.JSON:Array;

export namespace Poco::JSON
{
    using Poco::JSON::Array;
}
