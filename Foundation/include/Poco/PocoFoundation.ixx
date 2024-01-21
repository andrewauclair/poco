module;

// make sure the module imports the classes. unsure on this.
#undef Foundation_EXPORTS
#define POCO_NO_AUTOMATIC_LIBS

// setup macros for exporting classes for the module
#define POCO_MODULES_EXPORT_Foundation export
#define POCO_MODULES_EXPORT_BEGIN_Foundation export {
#define POCO_MODULES_EXPORT_END_Foundation }

export module poco.foundation;

#include "Poco/Any.h"
#include "Poco/SharedPtr.h"