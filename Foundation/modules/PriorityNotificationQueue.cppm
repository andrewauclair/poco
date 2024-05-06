module;

#define POCO_ENABLE_MODULES

#include "PriorityNotificationQueue.cpp"

export module poco.foundation:PriorityNotificationQueue;

export namespace Poco
{
    using Poco::PriorityNotificationQueue;
}
