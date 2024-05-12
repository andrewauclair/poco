module;

#define POCO_ENABLE_MODULES

#include "Poco/TemporaryFile.h"

export module poco.foundation:temporaryFile;


export namespace Poco
{
	using Poco::TemporaryFile;
}
