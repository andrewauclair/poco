module;

#define POCO_ENABLE_MODULES

#include "RefCountedObject.cpp"

export module poco.foundation:refCountedObject;


export namespace Poco
{
	export using Poco::RefCountedObject;
}
