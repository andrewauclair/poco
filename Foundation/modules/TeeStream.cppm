module;

#define POCO_ENABLE_MODULES

#include "TeeStream.cpp"

export module poco.foundation:TeeStream;

export namespace Poco
{
    using Poco::TeeStreamBuf;
    using Poco::TeeIOS;
    using Poco::TeeInputStream;
    using Poco::TeeOutputStream;
}
