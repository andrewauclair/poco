module;

#define POCO_ENABLE_MODULES

#include "Error.cpp"

export module poco.foundation:Error;

export namespace Poco
{
    using Poco::Error;
}
