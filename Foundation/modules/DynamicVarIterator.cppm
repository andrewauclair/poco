module;

#define POCO_ENABLE_MODULES

#include "VarIterator.cpp"

export module poco.foundation:dynamicVarIterator;

export namespace Poco
{
export namespace Dynamic {
export using Poco::Dynamic::VarIterator;
}
}
