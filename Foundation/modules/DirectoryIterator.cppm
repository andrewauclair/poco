module;

#define POCO_ENABLE_MODULES

#include "DirectoryIterator.cpp"

export module poco.foundation:directoryIterator;


export namespace Poco
{
	using Poco::DirectoryIterator;
}
