module;

#define POCO_ENABLE_MODULES

#include "Stringifier.cpp"

export module poco.JSON:Stringifier;

export namespace Poco::JSON
{
	using Poco::JSON::JSONOptions;
	using Poco::JSON::toJSON;
}
