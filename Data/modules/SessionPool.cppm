module;

#define POCO_ENABLE_MODULES

#include "SessionPool.cpp"

export module poco.data:SessionPool;

export namespace Poco::Data
{
    using Poco::Data::SessionPool;
}
