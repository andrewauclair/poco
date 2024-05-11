module;

#define POCO_ENABLE_MODULES

#include "AbstractExtraction.cpp"

export module poco.data:AbstractExtraction;

export namespace Poco::Data
{
    using Poco::Data::AbstractExtraction;
}
