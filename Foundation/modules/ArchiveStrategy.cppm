module;

#define POCO_ENABLE_MODULES

#include "ArchiveStrategy.cpp"

export module poco.foundation:archiveStrategy;


export namespace Poco
{
	using Poco::ArchiveStrategy;
}
