module;

#define POCO_ENABLE_MODULES

#include "TemplateCache.cpp"

export module poco.JSON:TemplateCache;

export namespace Poco::JSON
{
    using Poco::JSON::TemplateCache;
}
