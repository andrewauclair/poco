module;

#define POCO_ENABLE_MODULES

#include "Formatter.cpp"

export module poco.foundation:Formatter;

export namespace Poco
{
    using Poco::Formatter;
}
