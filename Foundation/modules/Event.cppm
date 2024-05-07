module;

#define POCO_ENABLE_MODULES
#define POCO_GENERATE_MODULE

#include "Event.cpp"

export module poco.foundation:event;

export namespace Poco
{
	using Poco::Event;
}
