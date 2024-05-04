module;

#define POCO_ENABLE_MODULES

#include "Latin2Encoding.cpp"

export module poco.foundation:Latin2Encoding;

export namespace Poco
{
    using Poco::Latin2Encoding;
}
