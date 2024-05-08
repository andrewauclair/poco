module;

#define POCO_ENABLE_MODULES

#include "JSONString.cpp"

export module poco.foundation:JSONString;


export namespace Poco
{
	using Poco::JSONOptions::JSON_PRESERVE_KEY_ORDER;
	using Poco::toJSON;
}
