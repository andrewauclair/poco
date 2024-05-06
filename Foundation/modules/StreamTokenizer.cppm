module;

#define POCO_ENABLE_MODULES

#include "StreamTokenizer.cpp"

export module poco.foundation:StreamTokenizer;

export namespace Poco
{
    using Poco::StreamTokenizer;
}
