module;

#define POCO_ENABLE_MODULES

#include "Range.cpp"

export module poco.data:Range;

export namespace Poco::Data
{
    using Poco::Data::Range;
}
