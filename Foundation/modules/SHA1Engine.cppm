module;

#define POCO_ENABLE_MODULES

#include "SHA1Engine.cpp"

export module poco.foundation:SHA1Engine;

export namespace Poco
{
    using Poco::SHA1Engine;
}
