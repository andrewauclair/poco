module;

#define POCO_ENABLE_MODULES

#include "DynamicLOB.cpp"

export module poco.data:DynamicLOB;

export namespace Poco::Data
{
    //using Poco::Data::DynamicLOB;
}
