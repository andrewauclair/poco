module;

#define POCO_ENABLE_MODULES

#include "Base64Decoder.cpp"

export module poco.foundation:Base64Decoder;

export namespace Poco
{
    using Poco::Base64Decoder;
}
