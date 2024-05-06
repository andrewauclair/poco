module;

#define POCO_ENABLE_MODULES

#include "DigestStream.cpp"

export module poco.foundation:DigestStream;

export namespace Poco
{
    using Poco::DigestBuf;
    using Poco::DigestIOS;
    using Poco::DigestInputStream;
    using Poco::DigestOutputStream;
}
