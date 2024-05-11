module;

#define POCO_ENABLE_MODULES

#include "Transaction.cpp"

export module poco.data:Transaction;

export namespace Poco::Data
{
    using Poco::Data::Transaction;
}
