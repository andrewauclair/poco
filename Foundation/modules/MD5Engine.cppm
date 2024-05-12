module;

#define POCO_ENABLE_MODULES

#include "Poco/MD5Engine.h"

export module poco.foundation:MD5Engine;

export namespace Poco
{
    using Poco::MD5Engine;
}
