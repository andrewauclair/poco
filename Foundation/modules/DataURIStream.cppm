module;

#define POCO_ENABLE_MODULES

#include "DataURIStream.cpp"

export module poco.foundation:DataURIStream;

export namespace Poco
{
    using Poco::DataURIStream;
}
