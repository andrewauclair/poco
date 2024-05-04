module;

#define POCO_ENABLE_MODULES

#include "Timezone.cpp"

export module poco.foundation:Timezone;

export namespace Poco
{
    using Poco::Timezone;
}
