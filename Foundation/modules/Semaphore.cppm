module;

#define POCO_ENABLE_MODULES

#include "Semaphore.cpp"

export module poco.foundation:Semaphore;

export namespace Poco
{
    using Poco::Semaphore;
}
