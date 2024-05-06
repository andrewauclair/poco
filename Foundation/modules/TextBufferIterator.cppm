module;

#define POCO_ENABLE_MODULES

#include "TextBufferIterator.cpp"

export module poco.foundation:TextBufferIterator;

export namespace Poco
{
    using Poco::TextBufferIterator;
}
