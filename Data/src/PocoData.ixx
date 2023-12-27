module;

#undef Data_EXPORTS
#define Data_MODULE

#include "Poco/Data/LOB.h"
#include "Poco/Data/LOBStream.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/Data/Connector.h"
#include "Poco/Data/SessionPool.h"
#include "Poco/Data/SessionPoolContainer.h"
#include "Poco/Data/Statement.h"
#include "Poco/Data/StatementImpl.h"
#include "Poco/Data/AbstractSessionImpl.h"
#include "Poco/Data/AbstractExtractor.h"
#include "Poco/Data/JSONRowFormatter.h"

export module poco.data;

export namespace Poco::Data
{
	/*
	{
		export using namespace Poco::Data::Keywords;
	}*/

	export using Poco::Data::Connector;
	export using Poco::Data::LOB;
	export using Poco::Data::BLOB;
	export using Poco::Data::CLOB;
	export using Poco::Data::SessionFactory;
	export using Poco::Data::Session;
	export using Poco::Data::SessionPool;
	export using Poco::Data::SessionPoolContainer;
	export using Poco::Data::SessionPoolExhaustedException;
	export using Poco::Data::NotSupportedException;
	export using Poco::Data::SessionPoolExistsException;
	export using Poco::Data::SessionUnavailableException;
	export using Poco::Data::NotSupportedException;
	export using Poco::Data::UnknownDataBaseException;

	export using Poco::Data::SimpleRowFormatter;
	export using Poco::Data::JSONRowFormatter;

	export using Poco::Data::AbstractSessionImpl;

	export using Poco::Data::Statement;
	export using Poco::Data::StatementImpl;

	export using Poco::Data::AbstractExtractor;

	export using Poco::Data::CLOBInputStream;
	export using Poco::Data::CLOBOutputStream;
	export using Poco::Data::MetaColumn;
	export using Poco::Data::Column;

	export using Poco::Data::AbstractExtraction;
	export using Poco::Data::AbstractExtractionVec;
	export using Poco::Data::AbstractExtractionVecVec;
	export using Poco::Data::AbstractBinding;
	export using Poco::Data::AbstractBindingVec;
	export using Poco::Data::NotConnectedException;
	export using Poco::Data::Date;
	export using Poco::Data::Time;

	export using Poco::Data::swap;

	export namespace Keywords
	{
		export using Poco::Data::Keywords::now;
		export using Poco::Data::Keywords::into;
		export using Poco::Data::Keywords::limit;
		export using Poco::Data::Keywords::use;
	}
}
