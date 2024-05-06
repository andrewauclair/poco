# Sources
file(GLOB SRCS_G "src/*.cpp")
POCO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB_RECURSE HDRS_G "include/*.h")
POCO_HEADERS_AUTO(SRCS ${HDRS_G})

# Platform Specific
POCO_SOURCES_AUTO_PLAT(SRCS UNIX src/SyslogChannel.cpp)
POCO_HEADERS_AUTO(SRCS include/Poco/SyslogChannel.h)

POCO_SOURCES_AUTO_PLAT(SRCS WIN32
	src/WindowsConsoleChannel.cpp
	src/EventLogChannel.cpp
	)

# Version Resource
if(MSVC AND BUILD_SHARED_LIBS)
	source_group("Resources" FILES ${PROJECT_SOURCE_DIR}/DLLVersion.rc)
	list(APPEND SRCS ${PROJECT_SOURCE_DIR}/DLLVersion.rc)
endif()

# Messages
POCO_MESSAGES(SRCS Logging src/pocomsg.mc)

# If POCO_UNBUNDLED is enabled we try to find the required packages
# The configuration will fail if the packages are not found
if(POCO_UNBUNDLED)
	find_package(PCRE2 REQUIRED)
	find_package(ZLIB REQUIRED)

	#HACK: Unicode.cpp requires functions from these files. The can't be taken from the library
	POCO_SOURCES(SRCS RegExp
		src/pcre2_ucd.c
		src/pcre2_tables.c
	)

else()
	# pcre2
	POCO_SOURCES(SRCS pcre2
		src/pcre2_auto_possess.c
		src/pcre2_chartables.c
		src/pcre2_compile.c
		src/pcre2_config.c
		src/pcre2_context.c
		src/pcre2_convert.c
		src/pcre2_dfa_match.c
		src/pcre2_error.c
		src/pcre2_extuni.c
		src/pcre2_find_bracket.c
		src/pcre2_jit_compile.c
		src/pcre2_maketables.c
		src/pcre2_match.c
		src/pcre2_match_data.c
		src/pcre2_newline.c
		src/pcre2_ord2utf.c
		src/pcre2_pattern_info.c
		src/pcre2_script_run.c
		src/pcre2_serialize.c
		src/pcre2_string_utils.c
		src/pcre2_study.c
		src/pcre2_substitute.c
		src/pcre2_substring.c
		src/pcre2_tables.c
		src/pcre2_ucd.c
		src/pcre2_valid_utf.c
		src/pcre2_xclass.c
	)

	# zlib
	POCO_HEADERS(SRCS zlib
		include/Poco/zconf.h
		include/Poco/zlib.h
		)

	POCO_SOURCES(SRCS zlib
		src/adler32.c
		src/compress.c
		src/crc32.c
		src/deflate.c
		src/infback.c
		src/inffast.c
		src/inflate.c
		src/inftrees.c
		src/trees.c
		src/zutil.c
	)
endif(POCO_UNBUNDLED)

if (POCO_GENERATE_MODULES)
	# pcre2
	POCO_SOURCES(C_CODE_SRCS pcre2
		src/pcre2_auto_possess.c
		src/pcre2_chartables.c
		src/pcre2_compile.c
		src/pcre2_config.c
		src/pcre2_context.c
		src/pcre2_convert.c
		src/pcre2_dfa_match.c
		src/pcre2_error.c
		src/pcre2_extuni.c
		src/pcre2_find_bracket.c
		src/pcre2_jit_compile.c
		src/pcre2_maketables.c
		src/pcre2_match.c
		src/pcre2_match_data.c
		src/pcre2_newline.c
		src/pcre2_ord2utf.c
		src/pcre2_pattern_info.c
		src/pcre2_script_run.c
		src/pcre2_serialize.c
		src/pcre2_string_utils.c
		src/pcre2_study.c
		src/pcre2_substitute.c
		src/pcre2_substring.c
		src/pcre2_tables.c
		src/pcre2_ucd.c
		src/pcre2_valid_utf.c
		src/pcre2_xclass.c
		#zlib
		src/adler32.c
		src/compress.c
		src/crc32.c
		src/deflate.c
		src/infback.c
		src/inffast.c
		src/inflate.c
		src/inftrees.c
		src/trees.c
		src/zutil.c
		
		src/pocomsg.mc
	)
	POCO_MESSAGES(GENERATED_MSGS Logging src/pocomsg.mc)
	add_library(Foundation ${C_CODE_SRCS} ${GENERATED_MSGS})
else()
	add_library(Foundation ${SRCS})
endif()

add_library(Poco::Foundation ALIAS Foundation)
set_target_properties(Foundation
	PROPERTIES
	VERSION ${SHARED_LIBRARY_VERSION} SOVERSION ${SHARED_LIBRARY_VERSION}
	OUTPUT_NAME PocoFoundation
	DEFINE_SYMBOL Foundation_EXPORTS
)

if (POCO_GENERATE_MODULES)
if (MSVC)
target_sources(Foundation PUBLIC
	FILE_SET windows_modules TYPE CXX_MODULES FILES
	modules/EventLogChannel.cppm
	modules/WindowsConsoleChannel.cppm
)
endif()
target_sources(Foundation PUBLIC

	FILE_SET cross_platform_modules TYPE CXX_MODULES FILES
	
	modules/AtomicCounter.cppm
	modules/Ascii.cppm
	modules/AsyncChannel.cppm
	modules/Bugcheck.cppm
	modules/Channel.cppm
	modules/EventChannel.cppm
	modules/NullChannel.cppm
	modules/FormattingChannel.cppm
	modules/SplitterChannel.cppm
	modules/Configurable.cppm
	modules/Debugger.cppm
	modules/Exception.cppm
	modules/Environment.cppm
	modules/LineEndingConverter.cppm
	modules/Logger.cppm
	modules/LoggingFactory.cppm
	modules/LoggingRegistry.cppm
	modules/Message.cppm
	modules/Mutex.cppm
	modules/PocoFoundation.cppm
	modules/RefCountedObject.cppm
	modules/Timestamp.cppm
	modules/Timespan.cppm
	modules/Runnable.cppm
	modules/FileChannel.cppm
	modules/FileStream.cppm
	modules/FileStreamFactory.cppm
	modules/SimpleFileChannel.cppm
	modules/Thread.cppm
	modules/ThreadLocal.cppm
	modules/File.cppm
	modules/Path.cppm
	modules/Event.cppm
	modules/ErrorHandler.cppm
	modules/PurgeStrategy.cppm
	modules/RotateStrategy.cppm
	modules/Notification.cppm
	modules/NotificationQueue.cppm
	modules/Format.cppm
	modules/UnicodeConverter.cppm
	modules/StringTokenizer.cppm
	modules/TextIterator.cppm
	modules/TextEncoding.cppm
	modules/UTF8String.cppm
	modules/UTF8Encoding.cppm
	modules/UTF16Encoding.cppm
	modules/UTF32Encoding.cppm
	modules/NumberParser.cppm
	modules/PatternFormatter.cppm
	modules/Process.cppm
	modules/LogFile.cppm
	modules/DateTime.cppm
	modules/DateTimeFormatter.cppm
	modules/DateTimeFormat.cppm
	modules/NumberFormatter.cppm
	modules/LocalDateTime.cppm
	modules/ArchiveStrategy.cppm
	modules/DateTimeParser.cppm
	modules/DirectoryIterator.cppm
	modules/Condition.cppm
	modules/TextConverter.cppm
	modules/ASCIIEncoding.cppm
	modules/ActiveThreadPool.cppm
	modules/FPEnvironment.cppm
	modules/Latin1Encoding.cppm
	modules/Latin2Encoding.cppm
	modules/Latin9Encoding.cppm
	modules/Windows1250Encoding.cppm
	modules/Windows1251Encoding.cppm
	modules/Windows1252Encoding.cppm
	modules/RWLock.cppm
	modules/NumericString.cppm
	modules/StreamCopier.cppm
	modules/ActiveDispatcher.cppm
	modules/RegularExpression.cppm
	modules/Timezone.cppm
	modules/Pipe.cppm
	modules/Formatter.cppm
	modules/NamedEvent.cppm
	modules/DeflatingStream.cppm
	modules/Unicode.cppm
	modules/Random.cppm
	modules/RandomStream.cppm
	modules/Error.cppm
	modules/JSONString.cppm
	modules/MemoryPool.cppm
	modules/MemoryStream.cppm
	modules/UUID.cppm
	modules/DynamicPair.cppm
	modules/DynamicStruct.cppm
	modules/DynamicVar.cppm
	modules/DynamicVarHolder.cppm
	modules/DynamicVarIterator.cppm
	modules/DynamicVarVisitor.cppm
	modules/URI.cppm
	modules/URIStreamOpener.cppm
	modules/URIStreamFactory.cppm
	modules/BinaryReader.cppm
	modules/BinaryWriter.cppm
	modules/StreamConverter.cppm
	modules/Checksum.cppm
	modules/InflatingStream.cppm
	modules/Timer.cppm
	modules/Stopwatch.cppm
	modules/Clock.cppm
	modules/ThreadPool.cppm
	modules/Hash.cppm
	modules/Void.cppm
	modules/TimedNotificationQueue.cppm
	modules/ConsoleChannel.cppm
	modules/TemporaryFile.cppm
)
endif()

if(POCO_UNBUNDLED)
	target_link_libraries(Foundation PUBLIC Pcre2::Pcre2 ZLIB::ZLIB)
	target_compile_definitions(Foundation PUBLIC POCO_UNBUNDLED)
endif(POCO_UNBUNDLED)

target_include_directories(Foundation
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(Foundation
	PUBLIC
		$<$<CONFIG:Debug>:_DEBUG>
		$<$<BOOL:${DISABLE_CPP14}>:POCO_DISABLE_CPP14>
		$<$<NOT:$<BOOL:${DISABLE_CPP14}>>:POCO_ENABLE_CPP14>
		$<$<BOOL:${DISABLE_CPP11}>:POCO_DISABLE_CPP11>
		$<$<NOT:$<BOOL:${DISABLE_CPP11}>>:POCO_ENABLE_CPP11>
)
target_compile_features(Foundation
	PUBLIC
		$<$<NOT:$<BOOL:${DISABLE_CPP11}>>:cxx_defaulted_move_initializers>
)
if(NOT DISABLE_CPP14 AND CMAKE_VERSION VERSION_GREATER "3.8")
	target_compile_features(Foundation PUBLIC cxx_std_14)
endif()

if(NOT BUILD_SHARED_LIBS)
	target_compile_definitions(Foundation
		PUBLIC
			POCO_STATIC
	)
endif()

if(WIN32)
	target_compile_definitions(Foundation PUBLIC POCO_OS_FAMILY_WINDOWS UNICODE _UNICODE)
	if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		target_compile_definitions(Foundation PUBLIC POCO_NO_AUTOMATIC_LIBS)
	endif()
	target_link_libraries(Foundation PUBLIC iphlpapi)
endif()

if(CYGWIN)
	target_compile_definitions(Foundation PUBLIC POCO_NO_FPENVIRONMENT POCO_NO_WSTRING _XOPEN_SOURCE=500 __BSD_VISIBLE)
else()
	if(UNIX AND NOT ANDROID)
		target_compile_definitions(Foundation PUBLIC POCO_OS_FAMILY_UNIX)
		if(APPLE)
			target_compile_definitions(Foundation PUBLIC POCO_HAVE_IPv6 POCO_NO_STAT64)
			target_link_libraries(Foundation PUBLIC ${CMAKE_DL_LIBS})
		else()
			target_compile_definitions(Foundation PUBLIC _REENTRANT _THREAD_SAFE _LARGEFILE64_SOURCE _FILE_OFFSET_BITS=64)
			if("${CMAKE_SYSTEM_NAME}" STREQUAL "QNX")
				target_compile_definitions(Foundation PUBLIC _QNX_SOURCE=1 POCO_HAVE_FD_POLL)
				target_link_libraries(Foundation PUBLIC m socket)
			elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "FreeBSD")
				target_compile_definitions(Foundation PUBLIC POCO_HAVE_FD_POLL)
				target_link_libraries(Foundation PUBLIC pthread ${CMAKE_DL_LIBS} rt)
			elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "AIX"  OR "${CMAKE_SYSTEM_NAME}" STREQUAL "GNU")
				target_compile_definitions(Foundation PUBLIC _XOPEN_SOURCE=500 POCO_HAVE_FD_POLL)
				target_link_libraries(Foundation PUBLIC pthread ${CMAKE_DL_LIBS} rt)
			else()
				target_compile_definitions(Foundation PUBLIC _XOPEN_SOURCE=500 POCO_HAVE_FD_EPOLL)
				target_link_libraries(Foundation PUBLIC pthread ${CMAKE_DL_LIBS} rt)
			endif()
		endif(APPLE)
	endif(UNIX AND NOT ANDROID)
endif(CYGWIN)

if(CMAKE_SYSTEM MATCHES "SunOS")
	target_compile_definitions(Foundation
		PUBLIC
			POCO_OS_FAMILY_UNIX
			_XOPEN_SOURCE=500
			_REENTRANT
			_THREAD_SAFE
			_LARGEFILE64_SOURCE
			_FILE_OFFSET_BITS=64
	)
	target_link_libraries(Foundation PUBLIC pthread socket xnet nsl resolv rt ${CMAKE_DL_LIBS})
endif()

if(MINGW)
	target_compile_definitions(Foundation
		PUBLIC
			WC_NO_BEST_FIT_CHARS=0x400
			POCO_WIN32_UTF8
			_WIN32
			MINGW32
			WINVER=0x500
			ODBCVER=0x0300
			POCO_THREAD_STACK_SIZE
	)
endif()

# SunPro C++
if(${CMAKE_CXX_COMPILER_ID} MATCHES "SunPro")
	target_compile_definitions(Foundation PUBLIC _BSD_SOURCE)
	target_compile_options(Foundation PUBLIC -library=stlport4)
endif()

# iOS
if(IOS)
	target_compile_definitions(Foundation
		PUBLIC
			POCO_HAVE_IPv6
			POCO_NO_FPENVIRONMENT
			POCO_NO_STAT64
			POCO_NO_SHAREDLIBS
			POCO_NO_NET_IFTYPES
	)
endif()

#Android
if(ANDROID)
	target_compile_definitions(Foundation
		PUBLIC
			POCO_NO_FPENVIRONMENT
			POCO_NO_WSTRING
			POCO_NO_SHAREDMEMORY
	)
	target_link_libraries(Foundation PUBLIC -llog)
endif()

POCO_INSTALL(Foundation)
POCO_GENERATE_PACKAGE(Foundation)

if(ENABLE_SAMPLES)
	add_subdirectory(samples)
endif()

if(ENABLE_TESTS)
	if(NOT BUILD_SHARED_LIBS)
		set_property(TARGET Foundation PROPERTY POSITION_INDEPENDENT_CODE ON) # This is needed to build TestLibrary.so as shared.
	endif()
	add_subdirectory(testsuite)
endif()
