module;

#define POCO_ENABLE_MODULES

#include "NumericString.cpp"

export module poco.foundation:NumericString;

export namespace Poco
{
    export using Poco::floatToStr;
    export using Poco::floatToFixedStr;
    export using Poco::doubleToStr;
    export using Poco::doubleToFixedStr;
    export using Poco::strToFloat;
    export using Poco::strToDouble;
}
