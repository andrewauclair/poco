module;

#define POCO_ENABLE_MODULES
#define POCO_GENERATE_MODULE

#include "Poco/Event.h"

export module poco.foundation:event;

export namespace Poco
{
	using Poco::Event;
}
