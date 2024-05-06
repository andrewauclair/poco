module;

#define POCO_ENABLE_MODULES

#include "Hash.cpp"

export module poco.foundation:hash;


export namespace Poco
{
	using Poco::Hash;
}
