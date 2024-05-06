module;

#define POCO_ENABLE_MODULES

#include "Task.cpp"

export module poco.foundation:Task;

export namespace Poco
{
    using Poco::Task;
}
