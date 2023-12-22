module;

// Cache
#include "Poco/AbstractCache.h"
#include "Poco/AbstractStrategy.h"
#include "Poco/AccessExpirationDecorator.h"
#include "Poco/AccessExpireCache.h"
#include "Poco/AccessExpireLRUCache.h"
#include "Poco/AccessExpireStrategy.h"
#include "Poco/ExpirationDecorator.h"
#include "Poco/ExpireCache.h"
#include "Poco/ExpireLRUCache.h"
#include "Poco/ExpireStrategy.h"
#include "Poco/KeyValueArgs.h"
#include "Poco/LRUCache.h"
#include "Poco/LRUStrategy.h"
#include "Poco/StrategyCollection.h"
#include "Poco/UniqueAccessExpireCache.h"
#include "Poco/UniqueAccessExpireLRUCache.h"
#include "Poco/UniqueAccessExpireStrategy.h"
#include "Poco/UniqueExpireCache.h"
#include "Poco/UniqueExpireLRUCache.h"
#include "Poco/UniqueExpireStrategy.h"
#include "Poco/ValidArgs.h"

// Core
#include "Poco/Any.h"
#include "Poco/Ascii.h"
#include "Poco/AtomicCounter.h"
#include "Poco/AutoPtr.h"
#include "Poco/AutoReleasePool.h"
#include "Poco/Buffer.h"
#include "Poco/Bugcheck.h"
#include "Poco/ByteOrder.h"
#include "Poco/Checksum.h"
#include "Poco/Config.h"
#include "Poco/Debugger.h"
#include "Poco/DynamicAny.h"
#include "Poco/DynamicAnyHolder.h"
#include "Poco/DynamicFactory.h"
#include "Poco/Dynamic/VarVisitor.h"
#include "Poco/Environment.h"
#include "Poco/Error.h"
#include "Poco/Exception.h"
#include "Poco/FIFOBuffer.h"
#include "Poco/FIFOBufferStream.h"
#include "Poco/Format.h"
#include "Poco/Foundation.h"
#include "Poco/FPEnvironment.h"
#include "Poco/Instantiator.h"
#include "Poco/JSONString.h"
#include "Poco/MemoryPool.h"
#include "Poco/MetaProgramming.h"
#include "Poco/NamedTuple.h"
#include "Poco/NestedDiagnosticContext.h"
#include "Poco/Nullable.h"
#include "Poco/NumberFormatter.h"
#include "Poco/NumberParser.h"
#include "Poco/NumericString.h"
#include "Poco/ObjectPool.h"
#include "Poco/Optional.h"
#include "Poco/OrderedMap.h"
#include "Poco/OrderedSet.h"
#include "Poco/Platform.h"
#include "Poco/Poco.h"
#include "Poco/RefCountedObject.h"
#include "Poco/SharedPtr.h"
#include "Poco/SingletonHolder.h"
#include "Poco/SortedDirectoryIterator.h"
#include "Poco/String.h"
#include "Poco/StringTokenizer.h"
#include "Poco/Tuple.h"
#include "Poco/TypeList.h"
#include "Poco/Types.h"
#include "Poco/UnWindows.h"
#include "Poco/Version.h"
#include "Poco/Void.h"

// Crypt
#include "Poco/DigestEngine.h"
#include "Poco/DigestStream.h"
#include "Poco/HMACEngine.h"
#include "Poco/MD4Engine.h"
#include "Poco/MD5Engine.h"
#include "Poco/PBKDF2Engine.h"
#include "Poco/Random.h"
#include "Poco/RandomStream.h"
#include "Poco/SHA1Engine.h"
#include "Poco/SHA2Engine.h"

// DateTime
#include "Poco/Clock.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeParser.h"
#include "Poco/LocalDateTime.h"
#include "Poco/Stopwatch.h"
#include "Poco/Timespan.h"
#include "Poco/Timestamp.h"
#include "Poco/Timezone.h"

// Dynamic
#include "Poco/Dynamic/Pair.h"
#include "Poco/Dynamic/Struct.h"
#include "Poco/Dynamic/Var.h"
#include "Poco/Dynamic/VarHolder.h"
#include "Poco/Dynamic/VarIterator.h"

// Events
#include "Poco/AbstractDelegate.h"
#include "Poco/AbstractEvent.h"
#include "Poco/AbstractPriorityDelegate.h"
#include "Poco/BasicEvent.h"
#include "Poco/DefaultStrategy.h"
#include "Poco/Delegate.h"
#include "Poco/DirectoryIteratorStrategy.h"
#include "Poco/EventArgs.h"
#include "Poco/Expire.h"
#include "Poco/FIFOEvent.h"
#include "Poco/FIFOStrategy.h"
#include "Poco/FunctionDelegate.h"
#include "Poco/FunctionPriorityDelegate.h"
#include "Poco/NotificationStrategy.h"
#include "Poco/PriorityDelegate.h"
#include "Poco/PriorityEvent.h"
#include "Poco/PriorityExpire.h"
#include "Poco/PriorityStrategy.h"
#include "Poco/RecursiveDirectoryIterator.h"
#include "Poco/RecursiveDirectoryIteratorImpl.h"

// Filesystem
#include "Poco/DirectoryIterator.h"
#include "Poco/DirectoryWatcher.h"
#include "Poco/File.h"
#include "Poco/Glob.h"
#include "Poco/Path.h"
#include "Poco/TemporaryFile.h"

// Hashing
#include "Poco/Hash.h"
#include "Poco/HashFunction.h"
#include "Poco/HashMap.h"
#include "Poco/HashSet.h"
#include "Poco/HashStatistic.h"
#include "Poco/HashTable.h"
#include "Poco/LinearHashTable.h"
#include "Poco/SimpleHashTable.h"

// Logging
#include "Poco/ArchiveStrategy.h"
#include "Poco/AsyncChannel.h"
#include "Poco/Channel.h"
#include "Poco/Configurable.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/EventChannel.h"
#include "Poco/EventLogChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/Formatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/LogFile.h"
#include "Poco/Logger.h"
#include "Poco/LoggingFactory.h"
#include "Poco/LoggingRegistry.h"
#include "Poco/LogStream.h"
#include "Poco/Message.h"
#include "Poco/NullChannel.h"
#include "Poco/PatternFormatter.h"
//#include "Poco/pocomsg.h"
#include "Poco/PurgeStrategy.h"
#include "Poco/RotateStrategy.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/SplitterChannel.h"
#include "Poco/StreamChannel.h"
#include "Poco/SyslogChannel.h"
#include "Poco/WindowsConsoleChannel.h"

// Notifications
#include "Poco/AbstractObserver.h"
#include "Poco/NObserver.h"
#include "Poco/Notification.h"
#include "Poco/NotificationCenter.h"
#include "Poco/NotificationQueue.h"
#include "Poco/Observer.h"
#include "Poco/PriorityNotificationQueue.h"
#include "Poco/TimedNotificationQueue.h"

// Processes
#include "Poco/NamedEvent.h"
#include "Poco/NamedMutex.h"
#include "Poco/PIDFile.h"
#include "Poco/Pipe.h"
#include "Poco/PipeStream.h"
#include "Poco/Process.h"
#include "Poco/ProcessRunner.h"
#include "Poco/SharedMemory.h"

// RegularExpression
#include "Poco/RegularExpression.h"

// SharedLibrary
#include "Poco/ClassLibrary.h"
#include "Poco/ClassLoader.h"
#include "Poco/Manifest.h"
#include "Poco/MetaObject.h"
#include "Poco/SharedLibrary.h"

// Streams
#include "Poco/Base32Decoder.h"
#include "Poco/Base32Encoder.h"
#include "Poco/Base64Decoder.h"
#include "Poco/Base64Encoder.h"
#include "Poco/BinaryReader.h"
#include "Poco/BinaryWriter.h"
#include "Poco/BufferAllocator.h"
#include "Poco/BufferedBidirectionalStreamBuf.h"
#include "Poco/BufferedStreamBuf.h"
#include "Poco/CountingStream.h"
#include "Poco/DeflatingStream.h"
#include "Poco/FileStream.h"
#include "Poco/HexBinaryDecoder.h"
#include "Poco/HexBinaryEncoder.h"
#include "Poco/InflatingStream.h"
#include "Poco/LineEndingConverter.h"
#include "Poco/MemoryStream.h"
#include "Poco/NullStream.h"
#include "Poco/StreamCopier.h"
#include "Poco/StreamTokenizer.h"
#include "Poco/StreamUtil.h"
#include "Poco/TeeStream.h"
#include "Poco/Token.h"
#include "Poco/UnbufferedStreamBuf.h"

// Tasks
#include "Poco/Task.h"
#include "Poco/TaskManager.h"
#include "Poco/TaskNotification.h"

// Text
#include "Poco/ASCIIEncoding.h"
#include "Poco/Latin1Encoding.h"
#include "Poco/Latin2Encoding.h"
#include "Poco/Latin9Encoding.h"
#include "Poco/ListMap.h"
#include "Poco/StreamConverter.h"
#include "Poco/TextBufferIterator.h"
#include "Poco/TextConverter.h"
#include "Poco/TextEncoding.h"
#include "Poco/TextIterator.h"
#include "Poco/Unicode.h"
#include "Poco/UnicodeConverter.h"
#include "Poco/UTF8Encoding.h"
#include "Poco/UTF8String.h"
#include "Poco/UTF16Encoding.h"
#include "Poco/UTF32Encoding.h"
#include "Poco/Windows1250Encoding.h"
#include "Poco/Windows1251Encoding.h"
#include "Poco/Windows1252Encoding.h"

// Threading
#include "Poco/ActiveDispatcher.h"
#include "Poco/ActiveMethod.h"
#include "Poco/ActiveResult.h"
#include "Poco/ActiveRunnable.h"
#include "Poco/ActiveStarter.h"
#include "Poco/Activity.h"
#include "Poco/Condition.h"
#include "Poco/ErrorHandler.h"
#include "Poco/Event.h"
#include "Poco/Mutex.h"
#include "Poco/Runnable.h"
#include "Poco/RunnableAdapter.h"
#include "Poco/RWLock.h"
#include "Poco/ScopedLock.h"
#include "Poco/ScopedUnlock.h"
#include "Poco/Semaphore.h"
#include "Poco/SignalHandler.h"
#include "Poco/SynchronizedObject.h"
#include "Poco/Thread.h"
#include "Poco/ThreadLocal.h"
#include "Poco/ThreadPool.h"
#include "Poco/ThreadTarget.h"
#include "Poco/Timer.h"

// URI
#include "Poco/DataURIStream.h"
#include "Poco/DataURIStreamFactory.h"
#include "Poco/FileStreamFactory.h"
#include "Poco/URI.h"
#include "Poco/URIStreamFactory.h"
#include "Poco/URIStreamOpener.h"

// UUID
#include "Poco/UUID.h"
#include "Poco/UUIDGenerator.h"

// this isn't in a group?
#include "Poco/Array.h"
#include "Poco/ordered_hash.h"

export module poco.foundation;

namespace Poco
{
	export using Poco::Any;
	export using Poco::AnyCast;

	export using Poco::Ascii;

	export using Poco::Base32Encoder;
	export using Poco::Base32Decoder;
	export using Poco::Base64Encoder;
	export using Poco::Base64Decoder;

	export using Poco::DataFormatException;
	export using Poco::ActiveMethod;
	export using Poco::ActiveResult;
	export using Poco::Event;
	export using Poco::ActiveDispatcher;
	export using Poco::Activity;
	export using Poco::Condition;
	export using Poco::Mutex;
	export using Poco::TimeoutException;
	export using Poco::Base64EncodingOptions;
	export using Poco::Timestamp;
	export using Poco::DateTime;
	export using Poco::Timespan;
	export using Poco::Timezone;
	export using Poco::AssertionViolationException;
	export using Poco::CountingInputStream;
	export using Poco::CountingOutputStream;
	export using Poco::DateTimeFormat;
	export using Poco::DateTimeFormatter;
	export using Poco::HashMap;
	export using Poco::LinearHashTable;
	export using Poco::Hash;
	export using Poco::HashTable;
	export using Poco::Stopwatch;
	export using Poco::NumberFormatter;
	export using Poco::format;
	export using Poco::ClassLoader;
	export using Poco::Manifest;
	export using Poco::SharedLibrary;
	export using Poco::AbstractMetaObject;
	export using Poco::NotFoundException;
	export using Poco::Path;
	export using Poco::File;
	export using Poco::ExpireLRUCache;
	export using Poco::FileChannel;
	export using Poco::Message;
	export using Poco::TemporaryFile;
	export using Poco::LocalDateTime;
	export using Poco::DirectoryIterator;
	export using Poco::InvalidArgumentException;
	//export using Poco::FIFOBufferStream;

	export using Poco::Exception;
	export using Poco::BadCastException;
	export using Poco::NullPointerException;
	export using Poco::InvalidAccessException;
	export using Poco::NullValueException;

	export using Poco::UInt8;
	export using Poco::UInt16;
	export using Poco::UInt32;
	export using Poco::UInt64;
	export using Poco::Int8;
	export using Poco::Int16;
	export using Poco::Int32;
	export using Poco::Int64;

	export using Poco::AutoPtr;
	export using Poco::SharedPtr;

	export using Poco::Array;

	export using Poco::AutoReleasePool;

	export using Poco::ByteOrder;

	export using Poco::Runnable;

	export using Poco::AtomicCounter;

	export using Poco::Environment;

	export using Poco::Buffer;
	export using Poco::BasicFIFOBuffer;
	export using Poco::FIFOBuffer;

	export using Poco::Thread;
	export using Poco::ThreadLocal;

	export using Poco::Nullable;
	export using Poco::Clock;
	export using Poco::Task;
	export using Poco::TextIterator;

	export using Poco::TypeList;
	export using Poco::NullTypeList;
	export using Poco::TypeListType;
	export using Poco::TypeGetter;
	export using Poco::TypeLocator;
	export using Poco::TypeAppender;
	export using Poco::TypeOneEraser;
	export using Poco::TypeAllEraser;
	export using Poco::TypeDuplicateEraser;
	export using Poco::TypeOneReplacer;
	export using Poco::TypeAllReplacer;
	export using Poco::Tuple;
	export using Poco::Void;
	export using Poco::FileNotFoundException;
	export using Poco::TaskStartedNotification;
	export using Poco::TaskCancelledNotification;
	export using Poco::TaskFinishedNotification;
	export using Poco::TaskFailedNotification;
	export using Poco::TaskProgressNotification;
	export using Poco::TaskCustomNotification;

	export using Poco::NoThreadAvailableException;
	export using Poco::SystemException;
	export using Poco::Observer;

	export using Poco::UUIDGenerator;
	export using Poco::UUID;
	export using Poco::TaskManager;

	export using Poco::SortedDirectoryIterator;

	export using Poco::StreamTokenizer;
	export using Poco::Token;
	export using Poco::InvalidToken;
	export using Poco::EOFToken;
	export using Poco::WhitespaceToken;

	export using Poco::URIStreamOpener;
	export using Poco::URIStreamFactory;
	export using Poco::URI;

	export using Poco::ThreadTarget;

	export using Poco::LineEnding;
	export using Poco::InputLineEndingConverter;
	export using Poco::OutputLineEndingConverter;
	export using Poco::StreamCopier;
	export using Poco::ListMap;

	export using Poco::HMACEngine;
	export using Poco::MD5Engine;
	export using Poco::SHA2Engine224;
	export using Poco::SHA2Engine256;
	export using Poco::SHA2Engine384;
	export using Poco::SHA2Engine512;
	export using Poco::SHA2Engine;
	export using Poco::DigestEngine;

	export using Poco::DateTimeParser;
	export using Poco::SyntaxException;

	export using Poco::MemoryInputStream;
	export using Poco::MemoryOutputStream;
	export using Poco::MemoryPool;
	export using Poco::LoggingFactory;
	export using Poco::Channel;
	export using Poco::ConsoleChannel;
	export using Poco::SimpleFileChannel;
	export using Poco::SplitterChannel;
	export using Poco::Formatter;
	export using Poco::PatternFormatter;
	export using Poco::Instantiator;

	export using Poco::AsyncChannel;
	export using Poco::FormattingChannel;
	export using Poco::ConsoleChannel;
	export using Poco::StreamChannel;

	export using Poco::DigestInputStream;
	export using Poco::DigestOutputStream;

	export using Poco::PathSyntaxException;

	export using Poco::NullInputStream;
	export using Poco::NullOutputStream;

	export using Poco::PBKDF2Engine;
	export using Poco::SHA1Engine;

	export using Poco::NamedMutex;
	export using Poco::OutOfMemoryException;
	export using Poco::NotImplementedException;

	export using Poco::NumberParser;
	export using Poco::MetaObject;
	export using Poco::FastMemoryPool;
	export using Poco::NDC;
	export using Poco::Logger;
	export using Poco::LogStream;
	export using Poco::LoggingRegistry;
	export using Poco::MD4Engine;
	export using Poco::MD5Engine;

	export using Poco::WindowsConsoleChannel;
	export using Poco::NamedTuple;

	export using Poco::PriorityNotificationQueue;
	export using Poco::Notification;
	export using Poco::RunnableAdapter;

	export using Poco::HexBinaryEncoder;
	export using Poco::HexBinaryDecoder;

	export using Poco::Process;
	export using Poco::ProcessHandle;
	export using Poco::Pipe;
	export using Poco::PipeInputStream;
	export using Poco::PipeOutputStream;

	export using Poco::TimedNotificationQueue;
	export using Poco::NotificationQueue;

	export using Poco::TextBufferIterator;
	export using Poco::Latin1Encoding;
	export using Poco::UTF8Encoding;
	export using Poco::UTF16Encoding;

	export using Poco::StringTokenizer;
	export using Poco::RangeException;

	export using Poco::AccessExpirationDecorator;

	export using Poco::UniqueExpireLRUCache;

	export using Poco::InflatingInputStream;
	export using Poco::InflatingOutputStream;
	export using Poco::DeflatingOutputStream;
	export using Poco::DeflatingInputStream;
	export using Poco::InflatingStreamBuf;
	export using Poco::DeflatingStreamBuf;

	export template<typename T, typename... Args>
	Poco::AutoPtr<T> makeAuto(Args&&... args);

	export using Poco::decimalSeparator;
	export using Poco::thousandSeparator;
	export using Poco::DataURIStream;

	export namespace Dynamic
	{
		export using Poco::Dynamic::Var;
		export using Poco::Dynamic::Pair;
		export using Poco::Dynamic::Struct;
		export using Poco::Dynamic::Visitor;
		export using Poco::Dynamic::Array;
	}
	export using Poco::PIDFile;
	export using Poco::ObjectPool;
	export using Poco::SharedMemory;
	export using Poco::RWLock;
	export using Poco::SimpleHashTable;
	export using Poco::Latin2Encoding;
	export using Poco::Latin9Encoding;
	export using Poco::Windows1250Encoding;
	export using Poco::Windows1251Encoding;
	export using Poco::Windows1252Encoding;
	export using Poco::DynamicStruct;
	export using Poco::FIFOBufferStream;

	export using Poco::OrderedDynamicStruct;
	export using Poco::FPE;

	export using Poco::FileInputStream;
	export using Poco::FileOutputStream;
	export using Poco::FileStream;

	export using Poco::Glob;
	export using Poco::HashSet;

	export using Poco::ExpireCache;
	export using Poco::LRUCache;


	export using Poco::SimpleRecursiveDirectoryIterator;
	export using Poco::SiblingsFirstRecursiveDirectoryIterator;

	export using Poco::NotificationCenter;
	export using Poco::NObserver;

	export using Poco::Delegate;
	export using Poco::Expire;
	export using Poco::FunctionDelegate;
	export using Poco::Random;
	export using Poco::OrderedMap;
	export using Poco::OrderedSet;
	export using Poco::NamedEvent;
	export using Poco::PurgeByCountStrategy;

	export using Poco::FunctionPriorityDelegate;
	export using Poco::PriorityDelegate;
	export using Poco::PriorityExpire;
	export using Poco::DynamicFactory;
	export using Poco::AccessExpireCache;
	export using Poco::InputStreamConverter;
	export using Poco::OutputStreamConverter;
	export using Poco::ASCIIEncoding;
	export using Poco::RegularExpression;
	export using Poco::RegularExpressionException;
	export using Poco::Semaphore;
	export using Poco::RandomInputStream;
	export using Poco::LibraryLoadException;
	export using Poco::LibraryAlreadyLoadedException;
	export using Poco::TextConverter;
	export using Poco::UTF8;
	export using Poco::ThreadPool;
	export using Poco::UniqueAccessExpireCache;
	export using Poco::ActiveThreadPool;
	export using Poco::TeeInputStream;
	export using Poco::TeeOutputStream;
	export using Poco::TextEncoding;
	export using Poco::UniqueExpireCache;
	export using Poco::ExpirationDecorator;
	export using Poco::UniqueAccessExpireLRUCache;
	export using Poco::AccessExpireLRUCache;
	export using Poco::ExistsException;
	export using Poco::DirectoryWatcher;
	
	export using Poco::InvalidAccessException;

	export template <typename I>
		bool strToInt(const char* pStr, I& outResult, short base, char thSep);

	export template <typename I>
		bool strToInt(const std::string& str, I& result, short base, char thSep);

	//export template <class TObj>
	//	Delegate<TObj, void, true> delegate(TObj* pObj, void (TObj::* NotifyMethod)(const void*));


	//export template <class TObj>
	//	Delegate<TObj, void, false> delegate(TObj* pObj, void (TObj::* NotifyMethod)());


	//export template <class TObj>
	//	Expire<void> delegate(TObj* pObj, void (TObj::* NotifyMethod)(const void*), Timestamp::TimeDiff expireMillisecs);


	//export template <class TObj>
	//	Expire<void> delegate(TObj* pObj, void (TObj::* NotifyMethod)(), Timestamp::TimeDiff expireMillisecs);


	//export Poco::delegate;
	/*inline Expire<void> delegate(void (*NotifyMethod)(const void*), Timestamp::TimeDiff expireMillisecs)
	{
		return Expire<void>(FunctionDelegate<void, true, true>(NotifyMethod), expireMillisecs);
	}


	inline Expire<void> delegate(void (*NotifyMethod)(void*), Timestamp::TimeDiff expireMillisecs)
	{
		return Expire<void>(FunctionDelegate<void, true, false>(NotifyMethod), expireMillisecs);
	}


	inline Expire<void> delegate(void (*NotifyMethod)(), Timestamp::TimeDiff expireMillisecs)
	{
		return Expire<void>(FunctionDelegate<void, false>(NotifyMethod), expireMillisecs);
	}


	inline FunctionDelegate<void, true, true> delegate(void (*NotifyMethod)(const void*))
	{
		return FunctionDelegate<void, true, true>(NotifyMethod);
	}


	inline FunctionDelegate<void, true, false> delegate(void (*NotifyMethod)(void*))
	{
		return FunctionDelegate<void, true, false>(NotifyMethod);
	}


	inline FunctionDelegate<void, false> delegate(void (*NotifyMethod)())
	{
		return FunctionDelegate<void, false>(NotifyMethod);
	}*/

	export template<class S>
		S trimLeft(const S& str);
	export template <class S>
	S& trimLeftInPlace(S& str);
	export template <class S>
	S trimRight(const S& str);
	export template <class S>
	S& trimRightInPlace(S& str);
	export template <class S>
	S trim(const S& str);
	export template <class S>
	S& trimInPlace(S& str);
	export template <class S>
	S toUpper(const S& str);
	export template <class S>
	S& toUpperInPlace(S& str);
	export template <class S>
	S toLower(const S& str);
	export template <class S>
	S& toLowerInPlace(S& str);
	export template <class S, class It>
	int icompare(
		const S& str,
		typename S::size_type pos,
		typename S::size_type n,
		It it2,
		It end2);
	export template <class S>
	int icompare(const S& str1, const S& str2);
	export template <class S>
	int icompare(const S& str1, typename S::size_type n1, const S& str2, typename S::size_type n2);
	export template <class S>
		int icompare(const S& str1, typename S::size_type n, const S& str2);
	export template <class S>
		int icompare(const S& str1, typename S::size_type pos, typename S::size_type n, const S& str2);
	export template <class S>
	int icompare(
		const S& str1,
		typename S::size_type pos1,
		typename S::size_type n1,
		const S& str2,
		typename S::size_type pos2,
		typename S::size_type n2);
	export template <class S>
	int icompare(
		const S& str1,
		typename S::size_type pos1,
		typename S::size_type n,
		const S& str2,
		typename S::size_type pos2);
	export template <class S>
	int icompare(
		const S& str,
		typename S::size_type pos,
		typename S::size_type n,
		const typename S::value_type* ptr);
	export template <class S>
	int icompare(
		const S& str,
		typename S::size_type pos,
		const typename S::value_type* ptr);
	export template <class S>
	int icompare(
		const S& str,
		const typename S::value_type* ptr);
	export template <class S>
	S translate(const S& str, const S& from, const S& to);
	export template <class S>
	S translate(const S& str, const typename S::value_type* from, const typename S::value_type* to);
	export template <class S>
	S& translateInPlace(S& str, const S& from, const S& to);
	export template <class S>
	S translateInPlace(S& str, const typename S::value_type* from, const typename S::value_type* to);
	export template <class S>
	S& replaceInPlace(S& str, const S& from, const S& to, typename S::size_type start);
	export template <class S>
	S& replaceInPlace(S& str, const typename S::value_type* from, const typename S::value_type* to, typename S::size_type start);
	export template <class S>
	S& replaceInPlace(S& str, const typename S::value_type from, const typename S::value_type to, typename S::size_type start);
	export template <class S>
	S& removeInPlace(S& str, const typename S::value_type ch, typename S::size_type start);
	export template <class S>
	S replace(const S& str, const S& from, const S& to, typename S::size_type start);
	export template <class S>
	S replace(const S& str, const typename S::value_type* from, const typename S::value_type* to, typename S::size_type start);
	export template <class S>
	S replace(const S& str, const typename S::value_type from, const typename S::value_type to, typename S::size_type start);
	export template <class S>
	S remove(const S& str, const typename S::value_type ch, typename S::size_type start);
	export template<typename T>
	std::size_t isubstr(const T& str, const T& sought);
	export using Poco::istring;
	export using Poco::translate;
	export using Poco::translateInPlace;
	export using Poco::replace;
	export using Poco::replaceInPlace;
	export using Poco::remove;
	export using Poco::removeInPlace;
	export using Poco::cat;
	export using Poco::startsWith;
	export using Poco::endsWith;
	export using Poco::strToFloat;
	export using Poco::strToDouble;
	export using Poco::intToStr;
	export using Poco::intToStr;
	export using Poco::floatToStr;
	export using Poco::doubleToStr;
	export using Poco::toJSON;
	export using Poco::CILess;
	export using Poco::isIntOverflow;
	export using Poco::safeMultiply;
	export using Poco::isSafeIntCast;
	export using Poco::safeIntCast;
	export using Poco::FPEnvironment;
	export using Poco::IntPtr;
	export using Poco::UIntPtr;
	export using Poco::KeyValueArgs;
	export using Poco::BasicEvent;
	export using Poco::EventArgs;
	export using Poco::JSONOptions;
	export using Poco::NullMutex;
	export using Poco::FIFOEvent;
	export using Poco::PriorityEvent;
	export using Poco::BinaryWriter;
	export using Poco::BinaryReader;
	export using Poco::MemoryBinaryWriter;
	export using Poco::MemoryBinaryReader;
	export using Poco::ProcessRunner;
	export using Poco::UnicodeConverter;
	export using Poco::FastMutex;
	export using Poco::Timer;
	export using Poco::TimerCallback;
	export using Poco::UTF16Char;
	export using Poco::UTF16String;
	export using Poco::UTF32Char;
	export using Poco::UTF32String;

	// binary numbers are supported, thus 64 (bits) + 1 (string terminating zero)
	export inline constexpr int POCO_MAX_INT_STRING_LEN = 65;
	// value from strtod.cc (double_conversion::kMaxSignificantDecimalDigits)
	export inline constexpr int POCO_MAX_FLT_STRING_LEN = 780;
}
