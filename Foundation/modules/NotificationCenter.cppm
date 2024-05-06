module;

#define POCO_ENABLE_MODULES

#include "NotificationCenter.cpp"

export module poco.foundation:NotificationCenter;

export namespace Poco
{
    using Poco::NotificationCenter;
}
