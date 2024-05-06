module;

#define POCO_ENABLE_MODULES

#include "RandomStream.cpp"

export module poco.foundation:randomStream;


export namespace Poco
{
	using Poco::RandomBuf;
	using Poco::RandomIOS;
	using Poco::RandomInputStream;
}
