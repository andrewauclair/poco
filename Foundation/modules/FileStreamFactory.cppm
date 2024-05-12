module;

#define POCO_ENABLE_MODULES

#include "Poco/FileStreamFactory.h"

export module poco.foundation:fileStreamFactory;


export namespace Poco
{
	using Poco::FileStreamFactory;
}
