module;

#define POCO_ENABLE_MODULES

#include "RotateStrategy.cpp"

export module poco.foundation:rotateStrategy;

export namespace Poco
{
	export using Poco::RotateStrategy;
}
