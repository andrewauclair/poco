module;

#define POCO_ENABLE_MODULES

#include "UUID.cpp"

export module poco.foundation:UUID;

export namespace Poco
{
    using Poco::UUID;
}
