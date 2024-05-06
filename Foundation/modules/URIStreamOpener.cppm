module;

#define POCO_ENABLE_MODULES

#include "URIStreamOpener.cpp"

export module poco.foundation:URIStreamOpener;

export namespace Poco
{
    using Poco::URIStreamOpener;
}
