module;

#define POCO_ENABLE_MODULES

#include "HexBinaryDecoder.cpp"

export module poco.foundation:HexBinaryDecoder;

export namespace Poco
{
    using Poco::HexBinaryDecoder;
}
