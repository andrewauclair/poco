module;

#define POCO_ENABLE_MODULES

#include "DeflatingStream.cpp"

export module poco.foundation:DeflatingStream;

export namespace Poco
{
    using Poco::DeflatingStreamBuf;
    using Poco::DeflatingIOS;
    using Poco::DeflatingOutputStream;
    using Poco::DeflatingInputStream;
}