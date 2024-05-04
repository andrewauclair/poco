module;

#define POCO_ENABLE_MODULES

#include "Thread.cpp"

export module poco.foundation:thread;

export namespace Poco
{
	export using Poco::Thread;
}
