module;

#define POCO_ENABLE_MODULES

#include "Connector.cpp"

export module poco.data.sqlite:Connector;

export namespace Poco::Data
{
    using Poco::Data::Connector;
}
