module;

#define POCO_ENABLE_MODULES

#include "TemporaryFile.cpp"

export module poco.foundation:temporaryFile;


export namespace Poco
{
	using Poco::TemporaryFile;
}
