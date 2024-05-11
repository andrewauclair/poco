if (POCO_GENERATE_MODULES)
	cmake_policy(SET CMP0155 NEW)
endif()

# Sources
file(GLOB SRCS_G "src/*.cpp")
POCO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB_RECURSE HDRS_G "include/*.h")
POCO_HEADERS_AUTO(SRCS ${HDRS_G})
POCO_SOURCES(SRCS pdjson src/pdjson.c)

# Version Resource
if(MSVC AND BUILD_SHARED_LIBS)
	source_group("Resources" FILES ${PROJECT_SOURCE_DIR}/DLLVersion.rc)
	list(APPEND SRCS ${PROJECT_SOURCE_DIR}/DLLVersion.rc)
endif()

if (POCO_GENERATE_MODULES)
	POCO_SOURCES(C_CODE_SRCS pdjson
		src/pdjson.c
	)
	add_library(JSON ${C_CODE_SRCS})
else()
	add_library(JSON ${SRCS})
endif()

add_library(Poco::JSON ALIAS JSON)
set_target_properties(JSON
	PROPERTIES
		VERSION ${SHARED_LIBRARY_VERSION} SOVERSION ${SHARED_LIBRARY_VERSION}
		OUTPUT_NAME PocoJSON
		DEFINE_SYMBOL JSON_EXPORTS
)

if (POCO_GENERATE_MODULES)
	target_sources(JSON PUBLIC
		FILE_SET cross_platform_modules TYPE CXX_MODULES FILES
	
		modules/PocoJSON.cppm
		modules/Array.cppm
		modules/Handler.cppm
		modules/JSONException.cppm
		modules/Object.cppm
		modules/ParseHandler.cppm
		modules/Parser.cppm
		modules/ParserImpl.cppm
		modules/PrintHandler.cppm
		modules/Query.cppm
		modules/Stringifier.cppm
		modules/Template.cppm
		modules/TemplateCache.cppm
	)
endif()

target_link_libraries(JSON PUBLIC Poco::Foundation)
target_include_directories(JSON
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(WIN32)
	target_compile_definitions(JSON PRIVATE _CRT_SECURE_NO_WARNINGS)
	set_source_files_properties(src/pdjson.c PROPERTIES LANGUAGE CXX)
	set_property(TARGET JSON PROPERTY C_STANDARD 99)
else()
	target_compile_features(JSON PUBLIC c_variadic_macros)
endif()

POCO_INSTALL(JSON)
POCO_GENERATE_PACKAGE(JSON)

if(ENABLE_SAMPLES)
	add_subdirectory(samples)
endif()

if(ENABLE_TESTS)
	add_subdirectory(testsuite)
endif()
