module;

#define POCO_ENABLE_MODULES

#include "MemoryStream.cpp"

export module poco.foundation:memoryStream;


export namespace Poco
{
	using Poco::MemoryIOS;
	using Poco::MemoryInputStream;
	using Poco::MemoryOutputStream;
}
