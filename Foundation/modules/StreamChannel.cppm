module;

#define POCO_ENABLE_MODULES

#include "StreamChannel.cpp"

export module poco.foundation:StreamChannel;

export namespace Poco
{
    using Poco::StreamChannel;
}
