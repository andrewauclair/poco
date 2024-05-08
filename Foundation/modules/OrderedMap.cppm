module;

#define POCO_ENABLE_MODULES

#include "Poco/OrderedMap.h"

export module poco.foundation:OrderedMap;

export namespace Poco
{
    using Poco::OrderedMap;
}
export namespace tsl
{
    using tsl::ordered_map;
}
