module;

#define POCO_ENABLE_MODULES

#include "NotificationQueue.cpp"

export module poco.foundation:notificationQueue;


export namespace Poco
{
	using Poco::NotificationQueue;
}
