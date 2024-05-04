module;

#define POCO_ENABLE_MODULES

#include "ASCIIEncoding.cpp"

export module poco.foundation:ASCIIEncoding;

export namespace Poco
{
    export using Poco::ASCIIEncoding;
}
