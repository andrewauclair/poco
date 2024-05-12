module;

#define POCO_ENABLE_MODULES

#include "Poco/NumericString.h"

export module poco.foundation:NumericString;

export namespace Poco
{
    using Poco::floatToStr;
    using Poco::floatToFixedStr;
    using Poco::doubleToStr;
    using Poco::doubleToFixedStr;
    using Poco::strToFloat;
    using Poco::strToDouble;
}
