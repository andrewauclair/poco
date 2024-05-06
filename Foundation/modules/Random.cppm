module;

#define POCO_ENABLE_MODULES

#include "Random.cpp"

export module poco.foundation:random;


export namespace Poco
{
	using Poco::Random;
}
