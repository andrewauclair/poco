module;

#define POCO_ENABLE_MODULES

#include "RegularExpression.cpp"

export module poco.foundation:RegularExpression;

export namespace Poco
{
    using Poco::RegularExpression;
}
