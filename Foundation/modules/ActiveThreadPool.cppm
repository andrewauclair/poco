module;

#define POCO_ENABLE_MODULES

#include "Poco/ActiveThreadPool.h"

export module poco.foundation:activeThreadPool;

export namespace Poco
{
    using Poco::ActiveThreadPool;
}
