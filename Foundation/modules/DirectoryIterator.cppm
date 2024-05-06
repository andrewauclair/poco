module;

#define POCO_ENABLE_MODULES

#include "DirectoryIterator.cpp"
#include "Poco/RecursiveDirectoryIterator.h"
export module poco.foundation:directoryIterator;


export namespace Poco
{
	using Poco::DirectoryIterator;
}
