module;

#define POCO_ENABLE_MODULES

#include "SessionPoolContainer.cpp"

export module poco.data:SessionPoolContainer;

export namespace Poco::Data
{
    using Poco::Data::SessionPoolContainer;
}
