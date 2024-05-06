module;

#define POCO_ENABLE_MODULES

#include "ThreadTarget.cpp"

export module poco.foundation:ThreadTarget;

export namespace Poco
{
    using Poco::ThreadTarget;
}
