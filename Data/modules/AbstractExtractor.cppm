module;

#define POCO_ENABLE_MODULES

#include "AbstractExtractor.cpp"

export module poco.data:AbstractExtractor;

export namespace Poco::Data
{
    using Poco::Data::AbstractExtractor;
}
