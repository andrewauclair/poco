module;

#define POCO_ENABLE_MODULES

#include "AbstractObserver.cpp"

export module poco.foundation:AbstractObserver;

export namespace Poco
{
    using Poco::AbstractObserver;
}
