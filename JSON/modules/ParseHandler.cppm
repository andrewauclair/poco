module;

#define POCO_ENABLE_MODULES

#include "ParseHandler.cpp"

export module poco.JSON:ParseHandler;

export namespace Poco::JSON
{
    using Poco::JSON::ParseHandler;
}
