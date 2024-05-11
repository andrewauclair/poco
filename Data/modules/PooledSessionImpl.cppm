module;

#define POCO_ENABLE_MODULES

#include "PooledSessionImpl.cpp"

export module poco.data:PooledSessionImpl;

export namespace Poco::Data
{
    using Poco::Data::PooledSessionImpl;
}
