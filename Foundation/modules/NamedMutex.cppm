module;

#define POCO_ENABLE_MODULES

#include "NamedMutex.cpp"

export module poco.foundation:NamedMutex;

export namespace Poco
{
    using Poco::NamedMutex;
}