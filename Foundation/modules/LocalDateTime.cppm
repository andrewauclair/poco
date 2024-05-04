module;

#define POCO_ENABLE_MODULES

#include "LocalDateTime.cpp"

export module poco.foundation:localDateTime;


export namespace Poco
{
	using Poco::LocalDateTime;
}
