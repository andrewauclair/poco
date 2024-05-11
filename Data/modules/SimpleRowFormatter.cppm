module;

#define POCO_ENABLE_MODULES

#include "SimpleRowFormatter.cpp"

export module poco.data:SimpleRowFormatter;

export namespace Poco::Data
{
    using Poco::Data::SimpleRowFormatter;
}
