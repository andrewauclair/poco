module;

#define POCO_ENABLE_MODULES

#include "SessionFactory.cpp"

export module poco.data:SessionFactory;

export namespace Poco::Data
{
    using Poco::Data::SessionFactory;
}
