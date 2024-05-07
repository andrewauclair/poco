module;

#define POCO_ENABLE_MODULES

#include "Object.cpp"

export module poco.JSON:Object;

export namespace Poco::JSON
{
    using Poco::JSON::Object;
}
