module;

#define POCO_ENABLE_MODULES

#include "Poco/Thread.h"

export module poco.foundation:thread;

export namespace Poco
{
	using Poco::Thread;
}
