module;

#define POCO_ENABLE_MODULES

#include "AbstractPreparator.cpp"

export module poco.data:AbstractPreparator;

export namespace Poco::Data
{
    using Poco::Data::AbstractPreparator;
}
