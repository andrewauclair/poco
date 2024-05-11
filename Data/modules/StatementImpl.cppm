module;

#define POCO_ENABLE_MODULES

#include "StatementImpl.cpp"

export module poco.data:StatementImpl;

export namespace Poco::Data
{
    using Poco::Data::StatementImpl;
}
