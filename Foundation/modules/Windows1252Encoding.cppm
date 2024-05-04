module;

#define POCO_ENABLE_MODULES

#include "Windows1252Encoding.cpp"

export module poco.foundation:Windows1252Encoding;

export namespace Poco
{
    using Poco::Windows1252Encoding;
}
