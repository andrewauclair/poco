module;

#define POCO_ENABLE_MODULES

#include "TimedNotificationQueue.cpp"

export module poco.foundation:timedNotificationQueue;


export namespace Poco
{
	using Poco::TimedNotificationQueue;
}
