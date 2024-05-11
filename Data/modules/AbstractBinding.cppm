module;

#define POCO_ENABLE_MODULES

#include "AbstractBinding.cpp"

export module poco.data:AbstractBinding;

export namespace Poco::Data
{
    using Poco::Data::AbstractBinding;
}
