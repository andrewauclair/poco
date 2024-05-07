module;

#define POCO_ENABLE_MODULES

#include "JSONException.cpp"

export module poco.JSON:JSONException;

export namespace Poco::JSON
{
    using Poco::JSON::JSONException;
}
