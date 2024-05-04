module;

#define POCO_ENABLE_MODULES

#include "Exception.cpp"

export module poco.foundation:exception;

export namespace Poco
{
	export using Poco::Exception;
	export using Poco::LogicException;
	export using Poco::AssertionViolationException;
	export using Poco::NullPointerException;
	export using Poco::NullValueException;
	export using Poco::BugcheckException;
	export using Poco::InvalidArgumentException;
	export using Poco::NotImplementedException;
	export using Poco::RangeException;
	export using Poco::IllegalStateException;
	export using Poco::InvalidAccessException;
	export using Poco::SignalException;
	export using Poco::UnhandledException;

	export using Poco::RuntimeException;
	export using Poco::NotFoundException;
	export using Poco::ExistsException;
	export using Poco::TimeoutException;
	export using Poco::SystemException;
	export using Poco::RegularExpressionException;
	export using Poco::LibraryLoadException;
	export using Poco::LibraryAlreadyLoadedException;
	export using Poco::NoThreadAvailableException;
	export using Poco::PropertyNotSupportedException;
	export using Poco::PoolOverflowException;
	export using Poco::NoPermissionException;
	export using Poco::OutOfMemoryException;
	export using Poco::DataException;
	
	export using Poco::DataFormatException;
	export using Poco::SyntaxException;
	export using Poco::CircularReferenceException;
	export using Poco::PathSyntaxException;
	export using Poco::IOException;
	export using Poco::ProtocolException;
	export using Poco::FileException;
	export using Poco::FileExistsException;
	export using Poco::FileNotFoundException;
	export using Poco::PathNotFoundException;
	export using Poco::FileReadOnlyException;
	export using Poco::FileAccessDeniedException;
	export using Poco::CreateFileException;
	export using Poco::OpenFileException;
	export using Poco::WriteFileException;
	export using Poco::ReadFileException;
	export using Poco::FileNotReadyException;
	export using Poco::DirectoryNotEmptyException;
	export using Poco::UnknownURISchemeException;
	export using Poco::TooManyURIRedirectsException;
	export using Poco::URISyntaxException;
	
	export using Poco::ApplicationException;
	export using Poco::BadCastException;
}
