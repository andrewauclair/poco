module;

#define POCO_ENABLE_MODULES

#include "JSONRowFormatter.cpp"

export module poco.data:JSONRowFormatter;

export namespace Poco::Data
{
    using Poco::Data::JSONRowFormatter;
}
