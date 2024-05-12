module;

#define POCO_ENABLE_MODULES

#include "Poco/ThreadLocal.h"

export module poco.foundation:threadLocal;

export namespace Poco
{
	using Poco::ThreadLocal;
}
