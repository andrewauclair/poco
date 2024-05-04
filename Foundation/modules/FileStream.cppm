module;

#define POCO_ENABLE_MODULES

#include "FileStream.cpp"

export module poco.foundation:fileStream;


export namespace Poco
{
	export using Poco::FileStream;
}
