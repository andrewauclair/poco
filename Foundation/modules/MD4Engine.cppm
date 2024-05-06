module;

#define POCO_ENABLE_MODULES

#include "MD4Engine.cpp"

export module poco.foundation:MD4Engine;

export namespace Poco
{
    using Poco::MD4Engine;
}
