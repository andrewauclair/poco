module;

#define POCO_ENABLE_MODULES

#include "DataException.cpp"

export module poco.data:DataException;

export namespace Poco::Data
{
    using Poco::Data::DataException;
}
