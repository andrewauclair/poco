module;

#define POCO_ENABLE_MODULES

#include "File.cpp"

export module poco.foundation:File;

export namespace Poco
{
	using Poco::File;
}
