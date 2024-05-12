module;

#define POCO_ENABLE_MODULES

#include "Poco/InflatingStream.h"

export module poco.foundation:inflatingStream;


export namespace Poco
{
	using Poco::InflatingStreamBuf;
	using Poco::InflatingIOS;
	using Poco::InflatingInputStream;
	using Poco::InflatingOutputStream;
}
