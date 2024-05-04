module;

#define POCO_ENABLE_MODULES

#include "Pipe.cpp"
#include "PipeImpl.cpp"

export module poco.foundation:Pipe;

export namespace Poco
{
    using Poco::Pipe;
}
