module;

#define POCO_ENABLE_MODULES

#include "Notification.cpp"

export module poco.foundation:notification;


export namespace Poco
{
	using Poco::Notification;
}
