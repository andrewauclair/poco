module;

#define POCO_ENABLE_MODULES

#include "Poco/SharedLibrary.h"

export module poco.foundation:SharedLibrary;

export namespace Poco
{
    using Poco::SharedLibrary;
}
