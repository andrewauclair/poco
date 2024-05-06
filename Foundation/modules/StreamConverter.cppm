module;

#define POCO_ENABLE_MODULES

#include "StreamConverter.cpp"

export module poco.foundation:streamConverter;

export namespace Poco
{
    using Poco::StreamConverterBuf;
    using Poco::StreamConverterIOS;
    using Poco::InputStreamConverter;
    using Poco::OutputStreamConverter;
}
