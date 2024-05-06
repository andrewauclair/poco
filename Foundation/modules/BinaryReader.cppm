module;

#define POCO_ENABLE_MODULES

#include "BinaryReader.cpp"

export module poco.foundation:binaryReader;


export namespace Poco
{
	using Poco::BinaryReader;
}
