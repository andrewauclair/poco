module;

#define POCO_ENABLE_MODULES

#include "Position.cpp"

export module poco.data:Position;

export namespace Poco::Data
{
    using Poco::Data::Position;
}
