module;

#define POCO_ENABLE_MODULES

#include "Bulk.cpp"

export module poco.data:Bulk;

export namespace Poco::Data
{
    using Poco::Data::Bulk;
}
