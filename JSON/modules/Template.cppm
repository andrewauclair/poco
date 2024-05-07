module;

#define POCO_ENABLE_MODULES

#include "Template.cpp"

export module poco.JSON:Template;

export namespace Poco::JSON
{
    using Poco::JSON::Template;
}
