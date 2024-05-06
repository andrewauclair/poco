module;

#define POCO_ENABLE_MODULES

#include "Base32Encoder.cpp"

export module poco.foundation:Base32Encoder;

export namespace Poco
{
    using Poco::Base32Encoder;
}
