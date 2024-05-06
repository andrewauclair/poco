module;

#define POCO_ENABLE_MODULES

#include "DirectoryIteratorStrategy.cpp"

export module poco.foundation:DirectoryIteratorStrategy;

export namespace Poco
{
    using Poco::TraverseBase;
    using Poco::ChildrenFirstTraverse;
    using Poco::SiblingsFirstTraverse;
}
