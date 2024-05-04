module;

#define POCO_ENABLE_MODULES

#include "Windows1251Encoding.cpp"

export module poco.foundation:Windows1251Encoding;

export namespace Poco
{
    export using Poco::Windows1251Encoding;
}
