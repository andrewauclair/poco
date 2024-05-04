module;

#define POCO_ENABLE_MODULES

#include "NamedEvent.cpp"

export module poco.foundation:NamedEvent;

export namespace Poco
{
    using Poco::NamedEvent;
}
