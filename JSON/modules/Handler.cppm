module;

#define POCO_ENABLE_MODULES

#include "Handler.cpp"

export module poco.JSON:Handler;

export namespace Poco::JSON
{
    using Poco::JSON::Handler;
}
