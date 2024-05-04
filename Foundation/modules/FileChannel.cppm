module;

#define POCO_ENABLE_MODULES

#include "FileChannel.cpp"

export module poco.foundation:fileChannel;


export namespace Poco
{
	using Poco::FileChannel;
}
