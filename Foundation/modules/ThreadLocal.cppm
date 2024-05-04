module;

#define POCO_ENABLE_MODULES

#include "ThreadLocal.cpp"

export module poco.foundation:threadLocal;

export namespace Poco
{
	export using Poco::ThreadLocal;
}
