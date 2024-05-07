module;

#define POCO_ENABLE_MODULES

#include "PrintHandler.cpp"

export module poco.JSON:PrintHandler;

export namespace Poco::JSON
{
    using Poco::JSON::PrintHandler;
}
