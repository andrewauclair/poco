module;

#define POCO_ENABLE_MODULES

#include "Timestamp.cpp"

export module poco.foundation:timestamp;

export namespace Poco
{
	export using Poco::Timestamp;
}
