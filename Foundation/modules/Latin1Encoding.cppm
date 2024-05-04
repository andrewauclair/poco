module;

#define POCO_ENABLE_MODULES

#include "Latin1Encoding.cpp"

export module poco.foundation:Latin1Encoding;

export namespace Poco
{
    using Poco::Latin1Encoding;
}
