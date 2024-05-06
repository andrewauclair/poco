module;

#define POCO_ENABLE_MODULES

#include "DigestEngine.cpp"

export module poco.foundation:DigestEngine;

export namespace Poco
{
    using Poco::DigestEngine;
}
