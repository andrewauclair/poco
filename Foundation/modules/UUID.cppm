module;

#define POCO_ENABLE_MODULES

#include "Poco/UUID.h"

export module poco.foundation:UUID;

export namespace Poco
{
    using Poco::UUID;
}
