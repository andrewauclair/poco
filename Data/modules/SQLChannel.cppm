module;

#define POCO_ENABLE_MODULES

#include "SQLChannel.cpp"

export module poco.data:SQLChannel;

export namespace Poco::Data
{
    using Poco::Data::SQLChannel;
}
