module;

#define POCO_ENABLE_MODULES

#include "StreamCopier.cpp"

export module poco.foundation:StreamCopier;

export namespace Poco
{
    export using Poco::StreamCopier;
}
