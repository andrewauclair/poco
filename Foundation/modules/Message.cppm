module;

#define POCO_ENABLE_MODULES

#include "Message.cpp"

export module poco.foundation:message;


export namespace Poco
{
	export using Poco::Message;
}
