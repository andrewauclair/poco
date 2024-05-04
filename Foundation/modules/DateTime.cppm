module;

#define POCO_ENABLE_MODULES

#include "DateTime.cpp"

export module poco.foundation:dateTime;


export namespace Poco
{
	export using Poco::DateTime;
}
