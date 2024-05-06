module;

#define POCO_ENABLE_MODULES

#include "Base32Decoder.cpp"

export module poco.foundation:Base32Decoder;

export namespace Poco
{
    using Poco::Base32Decoder;
}
