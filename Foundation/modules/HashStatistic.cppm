module;

#define POCO_ENABLE_MODULES

#include "HashStatistic.cpp"

export module poco.foundation:HashStatistic;

export namespace Poco
{
    using Poco::HashStatistic;
}
