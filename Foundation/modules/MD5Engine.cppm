module;

#define POCO_ENABLE_MODULES

#include "MD5Engine.cpp"

export module poco.foundation:MD5Engine;

export namespace Poco
{
    using Poco::MD5Engine;
}
