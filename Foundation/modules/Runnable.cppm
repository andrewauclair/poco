module;

#define POCO_ENABLE_MODULES

#include "Runnable.cpp"

export module poco.foundation:runnable;


export namespace Poco
{
	using Poco::Runnable;
}