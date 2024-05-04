module;

#define POCO_ENABLE_MODULES

#include "Event.cpp"

export module poco.foundation:event;

export namespace Poco
{
	using Poco::Event;
}
