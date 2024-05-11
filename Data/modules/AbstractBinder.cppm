module;

#define POCO_ENABLE_MODULES

#include "AbstractBinder.cpp"

export module poco.data:AbstractBinder;

export namespace Poco::Data
{
    using Poco::Data::AbstractBinder;
}
