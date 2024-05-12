module;

#define POCO_ENABLE_MODULES

#include "Poco/SharedMemory.h"

export module poco.foundation:SharedMemory;

export namespace Poco
{
    using Poco::SharedMemory;
}
