module;

#define POCO_ENABLE_MODULES

#include "SortedDirectoryIterator.cpp"

export module poco.foundation:SortedDirectoryIterator;

export namespace Poco
{
    using Poco::SortedDirectoryIterator;
}
