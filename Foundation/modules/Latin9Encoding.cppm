module;

#define POCO_ENABLE_MODULES

#include "Latin9Encoding.cpp"

export module poco.foundation:Latin9Encoding;

export namespace Poco
{
    export using Poco::Latin9Encoding;
}
