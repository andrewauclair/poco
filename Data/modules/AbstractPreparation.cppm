module;

#define POCO_ENABLE_MODULES

#include "AbstractPreparation.cpp"

export module poco.data:AbstractPreparation;

export namespace Poco::Data
{
    using Poco::Data::AbstractPreparation;
}
