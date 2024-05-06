module;

#define POCO_ENABLE_MODULES

#include "Base64Encoder.cpp"

export module poco.foundation:Base64Encoder;

export namespace Poco
{
    using Poco::Base64EncoderBuf;
    using Poco::Base64EncoderIOS;
    using Poco::Base64Encoder;
}
