module;

#define POCO_ENABLE_MODULES

#include "FileStreamFactory.cpp"

export module poco.foundation:fileStreamFactory;


export namespace Poco
{
	using Poco::FileStreamFactory;
}
