module;

#define POCO_ENABLE_MODULES

#include "Windows1250Encoding.cpp"

export module poco.foundation:Windows1250Encoding;

export namespace Poco
{
    using Poco::Windows1250Encoding;
}
