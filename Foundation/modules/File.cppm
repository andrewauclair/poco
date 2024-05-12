module;

#define POCO_ENABLE_MODULES

#include "Poco/File.h"

export module poco.foundation:File;

export namespace Poco
{
	using Poco::File;
}
