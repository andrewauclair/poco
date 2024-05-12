module;

#define POCO_ENABLE_MODULES

#include "Poco/PipeStream.h"

export module poco.foundation:PipeStream;

export namespace Poco
{
    using Poco::PipeStreamBuf;
    using Poco::PipeIOS;
    using Poco::PipeOutputStream;
    using Poco::PipeInputStream;
}
