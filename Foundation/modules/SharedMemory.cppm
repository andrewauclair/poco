module;

#define POCO_ENABLE_MODULES

#include "SharedMemory.cpp"

export module poco.foundation:SharedMemory;

export namespace Poco
{
    using Poco::SharedMemory;
}
