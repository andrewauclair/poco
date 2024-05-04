module;

#define POCO_ENABLE_MODULES

#include "Condition.cpp"

export module poco.foundation:condition;


export namespace Poco
{
	export using Poco::Condition;
}
