module;

#define POCO_ENABLE_MODULES

#include "FileStream.cpp"

export module poco.foundation:fileStream;


export namespace Poco
{
	using Poco::FileStream;
	using Poco::FileInputStream;
	using Poco::FileOutputStream;
}
