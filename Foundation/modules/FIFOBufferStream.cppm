module;

#define POCO_ENABLE_MODULES

#include "FIFOBufferStream.cpp"

export module poco.foundation:FIFOBufferStream;

export namespace Poco
{
    using Poco::FIFOBufferStream;
}
