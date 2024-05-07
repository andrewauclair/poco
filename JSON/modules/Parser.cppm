module;

#define POCO_ENABLE_MODULES

#include "Parser.cpp"

export module poco.JSON:Parser;

export namespace Poco::JSON
{
    using Poco::JSON::Parser;
}
