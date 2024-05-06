module;

#define POCO_ENABLE_MODULES

#include "URIStreamFactory.cpp"

export module poco.foundation:URIStreamFactory;

export namespace Poco
{
    using Poco::URIStreamFactory;
}
