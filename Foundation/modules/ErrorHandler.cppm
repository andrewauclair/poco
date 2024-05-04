module;

#define POCO_ENABLE_MODULES

#include "ErrorHandler.cpp"

export module poco.foundation:errorHandler;

export namespace Poco
{
	using Poco::ErrorHandler;
}
