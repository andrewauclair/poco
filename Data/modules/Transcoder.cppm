module;

#define POCO_ENABLE_MODULES

#include "Transcoder.cpp"

export module poco.data:Transcoder;

export namespace Poco::Data
{
    using Poco::Data::Transcoder;
}
