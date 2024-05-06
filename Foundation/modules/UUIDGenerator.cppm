module;

#define POCO_ENABLE_MODULES

#include "UUIDGenerator.cpp"

export module poco.foundation:UUIDGenerator;

export namespace Poco
{
    using Poco::UUIDGenerator;
}
