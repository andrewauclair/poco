module;

#define POCO_ENABLE_MODULES

#include "RWLock.cpp"

export module poco.foundation:RWLock;

export namespace Poco
{
    export using Poco::RWLock;
}
