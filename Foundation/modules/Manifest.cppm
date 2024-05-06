module;

#define POCO_ENABLE_MODULES

#include "Manifest.cpp"

export module poco.foundation:Manifest;

export namespace Poco
{
    using Poco::Manifest;
}
