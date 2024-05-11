module;

#define POCO_ENABLE_MODULES

#include "StatementCreator.cpp"

export module poco.data:StatementCreator;

export namespace Poco::Data
{
    using Poco::Data::StatementCreator;
}
