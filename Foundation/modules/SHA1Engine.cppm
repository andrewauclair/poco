module;

#define POCO_ENABLE_MODULES

#include "Poco/SHA1Engine.h"

export module poco.foundation:SHA1Engine;

export namespace Poco
{
    using Poco::SHA1Engine;
}
