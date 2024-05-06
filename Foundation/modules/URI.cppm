module;

#define POCO_ENABLE_MODULES

#include "URI.cpp"

export module poco.foundation:URI;

export namespace Poco
{
    using Poco::URI;
}
