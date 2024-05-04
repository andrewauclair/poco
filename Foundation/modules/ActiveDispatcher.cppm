module;

#define POCO_ENABLE_MODULES

#include "ActiveDispatcher.cpp"

export module poco.foundation:ActiveDispatcher;

export namespace Poco
{
    export using Poco::ActiveDispatcher;
}
