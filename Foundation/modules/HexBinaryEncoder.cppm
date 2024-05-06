module;

#define POCO_ENABLE_MODULES

#include "HexBinaryEncoder.cpp"

export module poco.foundation:HexBinaryEncoder;

export namespace Poco
{
    using Poco::HexBinaryEncoder;
}
