module;

#define POCO_ENABLE_MODULES

#include "Poco/Types.h"

export module poco.foundation:Types;

export namespace Poco
{
	using Poco::Int8;
	using Poco::UInt8;
	using Poco::Int16;
	using Poco::UInt16;
	using Poco::Int32;
	using Poco::UInt32;
	using Poco::Int64;
	using Poco::UInt64;
	using Poco::IntPtr;
	using Poco::UIntPtr;
}
