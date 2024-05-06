module;

#define POCO_ENABLE_MODULES

#include "TaskNotification.cpp"

export module poco.foundation:TaskNotification;

export namespace Poco
{
    using Poco::TaskNotification;
    using Poco::TaskStartedNotification;
    using Poco::TaskCancelledNotification;
    using Poco::TaskFinishedNotification;
    using Poco::TaskFailedNotification;
    using Poco::TaskProgressNotification;
}
