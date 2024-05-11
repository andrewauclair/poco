module;

#define POCO_ENABLE_MODULES

#include "SessionImpl.cpp"

export module poco.data:SessionImpl;

export namespace Poco::Data
{
    using Poco::Data::SessionImpl;
}
