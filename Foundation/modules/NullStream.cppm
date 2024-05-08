module;

#define POCO_ENABLE_MODULES

#include "NullStream.cpp"

export module poco.foundation:NullStream;

export namespace Poco
{
    using Poco::NullStreamBuf;
    using Poco::NullIOS;
    using Poco::NullInputStream;
    using Poco::NullOutputStream;
}