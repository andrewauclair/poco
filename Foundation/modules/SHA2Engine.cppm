module;

#define POCO_ENABLE_MODULES

#include "SHA2Engine.cpp"

export module poco.foundation:SHA2Engine;

export namespace Poco
{
    using Poco::SHA2Engine;
}
