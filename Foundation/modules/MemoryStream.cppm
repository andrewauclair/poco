module;

#define POCO_ENABLE_MODULES

#include "Poco/MemoryStream.h"

export module poco.foundation:memoryStream;


export namespace Poco
{
	using Poco::MemoryIOS;
	using Poco::MemoryInputStream;
	using Poco::MemoryOutputStream;
}
