module;

#define POCO_ENABLE_MODULES

#include "SimpleFileChannel.cpp"

export module poco.foundation:simpleFileChannel;


export namespace Poco
{
	using Poco::SimpleFileChannel;
}
