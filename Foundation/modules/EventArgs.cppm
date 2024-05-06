module;

#define POCO_ENABLE_MODULES

#include "EventArgs.cpp"

export module poco.foundation:EventArgs;

export namespace Poco
{
    using Poco::EventArgs;
}
