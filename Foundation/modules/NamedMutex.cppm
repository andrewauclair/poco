module;

#define POCO_ENABLE_MODULES

#include "Poco/NamedMutex.h"

export module poco.foundation:NamedMutex;

export namespace Poco
{
    using Poco::NamedMutex;
}
