module;

#define POCO_ENABLE_MODULES

#include "SharedLibrary.cpp"

export module poco.foundation:SharedLibrary;

export namespace Poco
{
    using Poco::SharedLibrary;
}
