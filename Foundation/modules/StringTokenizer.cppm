module;

#define POCO_ENABLE_MODULES

#include "StringTokenizer.cpp"

export module poco.foundation:stringTokenizer;


export namespace Poco
{
	using Poco::StringTokenizer;
}
