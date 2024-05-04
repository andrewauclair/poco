module;

#define POCO_ENABLE_MODULES

#include "DeflatingStream.cpp"

export module poco.foundation:DeflatingStream;

export namespace Poco
{
    export using Poco::DeflatingStreamBuf;
    export using Poco::DeflatingIOS;
    export using Poco::DeflatingOutputStream;
    export using Poco::DeflatingInputStream;
}
