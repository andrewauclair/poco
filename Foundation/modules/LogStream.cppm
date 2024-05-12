module;

#define POCO_ENABLE_MODULES

#include "Poco/LogStream.h"

export module poco.foundation:LogStream;

export namespace Poco
{
    using Poco::LogStream;
}
