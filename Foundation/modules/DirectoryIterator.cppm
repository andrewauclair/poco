module;

#define POCO_ENABLE_MODULES

#include "DirectoryIterator.cpp"

export module poco.foundation:directoryIterator;


export namespace Poco
{
	export using Poco::DirectoryIterator;
}
