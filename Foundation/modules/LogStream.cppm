module;

#define POCO_ENABLE_MODULES

#include "LogStream.cpp"

export module poco.foundation:LogStream;

export namespace Poco
{
    using Poco::LogStream;
}
