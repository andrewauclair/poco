module;

#define POCO_ENABLE_MODULES

#include "Path.cpp"

export module poco.foundation:path;

export namespace Poco
{
	export using Poco::Path;
}
