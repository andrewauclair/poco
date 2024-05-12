module;

#define POCO_ENABLE_MODULES

#include "Poco/DirectoryIterator.h"
#include "Poco/RecursiveDirectoryIterator.h"
export module poco.foundation:directoryIterator;


export namespace Poco
{
	using Poco::DirectoryIterator;
}
