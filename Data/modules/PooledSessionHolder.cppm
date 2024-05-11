module;

#define POCO_ENABLE_MODULES

#include "PooledSessionHolder.cpp"

export module poco.data:PooledSessionHolder;

export namespace Poco::Data
{
    using Poco::Data::PooledSessionHolder;
}
