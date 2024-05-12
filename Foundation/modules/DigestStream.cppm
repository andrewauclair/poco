module;

#define POCO_ENABLE_MODULES

#include "Poco/DigestStream.h"

export module poco.foundation:DigestStream;

export namespace Poco
{
    using Poco::DigestBuf;
    using Poco::DigestIOS;
    using Poco::DigestInputStream;
    using Poco::DigestOutputStream;
}
