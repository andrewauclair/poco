module;

#define POCO_ENABLE_MODULES

#include "ActiveThreadPool.cpp"

export module poco.foundation:activeThreadPool;

export namespace Poco
{
    using Poco::ActiveThreadPool;
}
