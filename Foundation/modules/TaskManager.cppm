module;

#define POCO_ENABLE_MODULES

#include "TaskManager.cpp"

export module poco.foundation:TaskManager;

export namespace Poco
{
    using Poco::TaskManager;
}
