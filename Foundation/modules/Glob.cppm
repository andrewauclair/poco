module;

#define POCO_ENABLE_MODULES

#include "Poco/Glob.h"

export module poco.foundation:Glob;

export namespace Poco
{
    using Poco::Glob;
}
