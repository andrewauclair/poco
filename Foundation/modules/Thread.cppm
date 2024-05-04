module;

#define POCO_ENABLE_MODULES

#include "Thread.cpp"

export module poco.foundation:thread;

export namespace Poco
{
	using Poco::Thread;
}
