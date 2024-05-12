module;

#define POCO_ENABLE_MODULES

#include "Poco/UUIDGenerator.h"

export module poco.foundation:UUIDGenerator;

export namespace Poco
{
    using Poco::UUIDGenerator;
}
