module;

//#include "Poco/Dynamic/Struct.h"
#include <string>

export module json_error;

//import poco.foundation;
//import poco.JSON;
import :test;

void foo()
{
	Poco::OrderedDynamicStruct ods;
	ods["Simpsons"].isStruct();
	ods["Simpsons"].isOrdered();
}
