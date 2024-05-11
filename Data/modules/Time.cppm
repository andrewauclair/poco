module;

#define POCO_ENABLE_MODULES

#include "Time.cpp"

export module poco.data:Time;

export namespace Poco::Data
{
    using Poco::Data::Time;
}
