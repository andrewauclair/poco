module;

#define POCO_ENABLE_MODULES

#include "CountingStream.cpp"

export module poco.foundation:CountingStream;

export namespace Poco
{
    using Poco::CountingStreamBuf;
    using Poco::CountingIOS;
    using Poco::CountingInputStream;
    using Poco::CountingOutputStream;
}
