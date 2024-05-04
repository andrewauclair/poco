module;

#define POCO_ENABLE_MODULES

#include "PurgeStrategy.cpp"

export module poco.foundation:purgeStrategy;

export namespace Poco
{
	using Poco::PurgeStrategy;
}
