module;

#define POCO_ENABLE_MODULES

#include "Poco/Manifest.h"

export module poco.foundation:Manifest;

export namespace Poco
{
    using Poco::Manifest;
}
