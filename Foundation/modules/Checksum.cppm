module;

#define POCO_ENABLE_MODULES

#include "Checksum.cpp"

export module poco.foundation:checksum;

export namespace Poco
{
	using Poco::Checksum;
}
