module;

#define POCO_ENABLE_MODULES

#include "DirectoryWatcher.cpp"

export module poco.foundation:DirectoryWatcher;

export namespace Poco
{
    using Poco::DirectoryWatcher;
}
