module;

#define POCO_ENABLE_MODULES

#include "Glob.cpp"

export module poco.foundation:Glob;

export namespace Poco
{
    using Poco::Glob;
}
