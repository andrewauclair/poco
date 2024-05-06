module;

#define POCO_ENABLE_MODULES

#include "Session.cpp"

export module poco.data:session;

export namespace Poco::Data
{
	using Poco::Data::Session;
}
