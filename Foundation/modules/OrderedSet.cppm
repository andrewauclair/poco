module;

#define POCO_ENABLE_MODULES

#include "Poco/OrderedSet.h"

export module poco.foundation:OrderedSet;

export namespace Poco
{
    using Poco::OrderedSet;
}
export namespace tsl
{
    using tsl::ordered_set;
}
