module;

#define POCO_ENABLE_MODULES

#include "BinaryWriter.cpp"

export module poco.foundation:binaryWriter;


export namespace Poco
{
	using Poco::BinaryWriter;
}
