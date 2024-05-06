module;

#define POCO_ENABLE_MODULES

#include "ProcessRunner.cpp"

export module poco.foundation:ProcessRunner;

export namespace Poco
{
    using Poco::ProcessRunner;
}
