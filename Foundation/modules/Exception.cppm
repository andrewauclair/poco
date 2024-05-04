module;

#define POCO_ENABLE_MODULES

#include "Exception.cpp"

export module poco.foundation:exception;

export namespace Poco
{
	using Poco::Exception;
	using Poco::LogicException;
	using Poco::AssertionViolationException;
	using Poco::NullPointerException;
	using Poco::NullValueException;
	using Poco::BugcheckException;
	using Poco::InvalidArgumentException;
	using Poco::NotImplementedException;
	using Poco::RangeException;
	using Poco::IllegalStateException;
	using Poco::InvalidAccessException;
	using Poco::SignalException;
	using Poco::UnhandledException;

	using Poco::RuntimeException;
	using Poco::NotFoundException;
	using Poco::ExistsException;
	using Poco::TimeoutException;
	using Poco::SystemException;
	using Poco::RegularExpressionException;
	using Poco::LibraryLoadException;
	using Poco::LibraryAlreadyLoadedException;
	using Poco::NoThreadAvailableException;
	using Poco::PropertyNotSupportedException;
	using Poco::PoolOverflowException;
	using Poco::NoPermissionException;
	using Poco::OutOfMemoryException;
	using Poco::DataException;
	
	using Poco::DataFormatException;
	using Poco::SyntaxException;
	using Poco::CircularReferenceException;
	using Poco::PathSyntaxException;
	using Poco::IOException;
	using Poco::ProtocolException;
	using Poco::FileException;
	using Poco::FileExistsException;
	using Poco::FileNotFoundException;
	using Poco::PathNotFoundException;
	using Poco::FileReadOnlyException;
	using Poco::FileAccessDeniedException;
	using Poco::CreateFileException;
	using Poco::OpenFileException;
	using Poco::WriteFileException;
	using Poco::ReadFileException;
	using Poco::FileNotReadyException;
	using Poco::DirectoryNotEmptyException;
	using Poco::UnknownURISchemeException;
	using Poco::TooManyURIRedirectsException;
	using Poco::URISyntaxException;
	
	using Poco::ApplicationException;
	using Poco::BadCastException;
}
