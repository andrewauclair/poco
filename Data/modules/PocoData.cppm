module;

#include "Poco/Data/Statement.h"
#include "Poco/Data/SQLChannel.h"
#include "Poco/Data/Limit.h"
#include "Poco/Data/RowFormatter.h"
#include "Poco/Data/StatementImpl.h"
#include "Poco/Data/RecordSet.h"
#include "Poco/Data/Date.h"
#include "Poco/Data/Transcoder.h"
#include "Poco/Data/AbstractExtractor.h"
#include "Poco/Data/AbstractPreparation.h"
#include "Poco/Data/JSONRowFormatter.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/AbstractPreparator.h"
#include "Poco/Data/PooledSessionImpl.h"
#include "Poco/Data/SessionImpl.h"
#include "Poco/Data/SimpleRowFormatter.h"
#include "Poco/Data/AbstractExtraction.h"
#include "Poco/Data/MetaColumn.h"
#include "Poco/Data/Connector.h"
#include "Poco/Data/Time.h"
#include "Poco/Data/Transaction.h"
#include "Poco/Data/AbstractBinding.h"
#include "Poco/Data/PooledSessionHolder.h"
#include "Poco/Data/Range.h"
#include "Poco/Data/Row.h"
#include "Poco/Data/DataException.h"
#include "Poco/Data/StatementCreator.h"
#include "Poco/Data/SessionPoolContainer.h"
#include "Poco/Data/RowIterator.h"
#include "Poco/Data/RowFilter.h"
#include "Poco/Data/ArchiveStrategy.h"
#include "Poco/Data/DynamicLOB.h"
#include "Poco/Data/AbstractBinder.h"
#include "Poco/Data/Position.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/Data/Bulk.h"
#include "Poco/Data/SessionPool.h"

export module poco.data;

export namespace Poco::Data
{
    using Poco::Data::Statement;
    using Poco::Data::SQLChannel;
    using Poco::Data::Limit;
    using Poco::Data::RowFormatter;
    using Poco::Data::StatementImpl;
    using Poco::Data::RecordSet;
    using Poco::Data::Date;
    using Poco::Data::Transcoder;
    using Poco::Data::AbstractExtractor;
    using Poco::Data::AbstractPreparation;
    using Poco::Data::JSONRowFormatter;
    using Poco::Data::Session;
    using Poco::Data::AbstractPreparator;
    using Poco::Data::PooledSessionImpl;
    using Poco::Data::SessionImpl;
    using Poco::Data::SimpleRowFormatter;
    using Poco::Data::AbstractExtraction;
    using Poco::Data::MetaColumn;
    using Poco::Data::Connector;
    using Poco::Data::Time;
    using Poco::Data::Transaction;
    using Poco::Data::AbstractBinding;
    using Poco::Data::PooledSessionHolder;
    using Poco::Data::Range;
    using Poco::Data::Row;
    using Poco::Data::DataException;
    using Poco::Data::StatementCreator;
    using Poco::Data::SessionPoolContainer;
    using Poco::Data::RowIterator;
    using Poco::Data::RowFilter;
    using Poco::Data::ArchiveStrategy;
    using Poco::Data::AbstractBinder;
    using Poco::Data::Position;
    using Poco::Data::SessionFactory;
    using Poco::Data::Bulk;
    using Poco::Data::SessionPool;
}
