module;

#define POCO_ENABLE_MODULES

#include "RecordSet.cpp"

export module poco.data:RecordSet;

export namespace Poco::Data
{
    using Poco::Data::RecordSet;
}
