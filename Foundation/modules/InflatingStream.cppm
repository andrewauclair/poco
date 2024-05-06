module;

#define POCO_ENABLE_MODULES

#include "InflatingStream.cpp"

export module poco.foundation:inflatingStream;


export namespace Poco
{
	using Poco::InflatingStreamBuf;
	using Poco::InflatingIOS;
	using Poco::InflatingInputStream;
	using Poco::InflatingOutputStream;
}
