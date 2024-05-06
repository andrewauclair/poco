module;

#define POCO_ENABLE_MODULES

#include "AsyncNotificationCenter.cpp"

export module poco.foundation:AsyncNotificationCenter;

export namespace Poco
{
    using Poco::AsyncNotificationCenter;
}
