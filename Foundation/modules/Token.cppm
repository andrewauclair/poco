module;

#define POCO_ENABLE_MODULES

#include "Token.cpp"

export module poco.foundation:Token;

export namespace Poco
{
    using Poco::Token;
}
