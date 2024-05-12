module;

#define POCO_ENABLE_MODULES

#include "Poco/RWLock.h"

export module poco.foundation:RWLock;

export namespace Poco
{
    using Poco::RWLock;
}
