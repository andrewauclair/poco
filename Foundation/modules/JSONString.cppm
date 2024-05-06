module;

#define POCO_ENABLE_MODULES

#include "JSONString.cpp"

export module poco.foundation:JSONString;


export namespace Poco
{
	using Poco::toJSON;
}
