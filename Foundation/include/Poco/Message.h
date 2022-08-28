//
// Message.h
//
// Library: Foundation
// Package: Logging
// Module:  Message
//
// Definition of the Message class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Message_INCLUDED
#define Foundation_Message_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Timestamp.h"
#include <map>

// Define to enable C++20 source_location usage in the Poco Logger
// NOTE: source_location must also be available to use this feature
#if __cpp_lib_source_location >= 201907L
#define POCO_ENABLE_SOURCE_LOCATION
#endif

// define the macros used to create source_location parameters and arguments
#ifdef POCO_ENABLE_SOURCE_LOCATION
#define POCO_SOURCE_LOCATION_PARAMETER_DECLARATION , std::source_location srcLocation = std::source_location::current()
#define POCO_SOURCE_LOCATION_PARAMETER_DEFINITION , std::source_location srcLocation
#define POCO_SOURCE_LOCATION_ARGUMENT , srcLocation

// include the source_location header if the feature is enabled
#if __has_include(<source_location>)
#include <source_location>
#elif __has_include(<experimental/source_location>)
#include <experimental/source_location>
using std::source_location = std::experimental::source_location;
#endif

#else
#define POCO_SOURCE_LOCATION_PARAMETER_DECLARATION // no-op
#define POCO_SOURCE_LOCATION_PARAMETER_DEFINITION // no-op
#define POCO_SOURCE_LOCATION_ARGUMENT // no-op
#endif

namespace Poco {


class Foundation_API Message
	/// This class represents a log message that is sent through a
	/// chain of log channels.
	///
	/// A Message contains a priority denoting the severity of the
	/// message, a source describing its origin, a text describing
	/// its meaning, the time of its creation, and an identifier of
	/// the process and thread that created the message.
	///
	/// Optionally a Message can also contain the source file path
	/// and line number of the statement generating the message.
	///
	/// A Message can also contain any number of named parameters
	/// that contain additional information about the event that
	/// caused the message.
{
public:
	typedef std::map<std::string, std::string> StringMap;

	enum Priority
	{
		PRIO_FATAL = 1,   /// A fatal error. The application will most likely terminate. This is the highest priority.
		PRIO_CRITICAL,    /// A critical error. The application might not be able to continue running successfully.
		PRIO_ERROR,       /// An error. An operation did not complete successfully, but the application as a whole is not affected.
		PRIO_WARNING,     /// A warning. An operation completed with an unexpected result.
		PRIO_NOTICE,      /// A notice, which is an information with just a higher priority.
		PRIO_INFORMATION, /// An informational message, usually denoting the successful completion of an operation.
		PRIO_DEBUG,       /// A debugging message.
		PRIO_TRACE        /// A tracing message. This is the lowest priority.
	};

	Message();
		/// Creates an empty Message.
		/// The thread and process ids are set.

	Message(const std::string& source, const std::string& text, Priority prio);
		/// Creates a Message with the given source, text and priority.
		/// The thread and process ids are set.
		
#ifdef POCO_ENABLE_SOURCE_LOCATION
	Message(const std::string& source, const std::string& text, Priority prio, std::source_location srcLocation);
		/// Creates a Message with the given source, text, priority and source location.
		/// The thread and process ids are set.
#endif
	Message(const std::string& source, const std::string& text, Priority prio, const char* file, int line);
		/// Creates a Message with the given source, text, priority,
		/// source file path and line.
		///
		/// The source file path must be a
		/// static string with a lifetime that's at least the lifetime
		/// of the message object (the string is not copied internally).
		/// Usually, this will be the path string obtained from the
		/// __FILE__ macro.
		///
		/// The thread and process ids are set.

	Message(const std::string& source, const std::string& text, Priority prio, const char* file, const char* function, int line);
	/// Creates a Message with the given source, text, priority,
	/// source file path and line.
	///
	/// The source file path must be a
	/// static string with a lifetime that's at least the lifetime
	/// of the message object (the string is not copied internally).
	/// Usually, this will be the path string obtained from the
	/// __FILE__ macro.
	///
	/// The thread and process ids are set.
	
	Message(const Message& msg);
		/// Creates a Message by copying another one.

	Message(Message&& msg) noexcept;
		/// Creates a Message by copying another one.

	Message(const Message& msg, const std::string& text);
		/// Creates a Message by copying all but the text from another message.

	~Message();
		/// Destroys the Message.

	Message& operator = (const Message& msg);
		/// Assignment operator.

	Message& operator = (Message&& msg) noexcept;
		/// Assignment operator.

	void swap(Message& msg);
		/// Swaps the message with another one.

	void setSource(const std::string& src);
		/// Sets the source of the message.

	const std::string& getSource() const;
		/// Returns the source of the message.

	void setText(const std::string& text);
		/// Sets the text of the message.

	const std::string& getText() const;
		/// Returns the text of the message.

	void setPriority(Priority prio);
		/// Sets the priority of the message.

	Priority getPriority() const;
		/// Returns the priority of the message.

	void setTime(const Timestamp& time);
		/// Sets the time of the message.

	const Timestamp& getTime() const;
		/// Returns the time of the message.

	void setThread(const std::string& thread);
		/// Sets the thread identifier for the message.

	const std::string& getThread() const;
		/// Returns the thread identifier for the message.

	void setTid(long pid);
		/// Sets the numeric thread identifier for the message.

	long getTid() const;
		/// Returns the numeric thread identifier for the message.

	long getOsTid() const;
		/// Returns the numeric thread identifier for the message.

	void setPid(long pid);
		/// Sets the process identifier for the message.

	long getPid() const;
		/// Returns the process identifier for the message.

	void setSourceFile(const char* file);
		/// Sets the source file path of the statement
		/// generating the log message.
		///
		/// File must be a static string, such as the value of
		/// the __FILE__ macro. The string is not copied
		/// internally for performance reasons.
	
	const char* getSourceFile() const;
		/// Returns the source file path of the code creating
		/// the message. May be 0 if not set.

	void setSourceFunction(const char* function);
		///  Sets the source function of the statement
		/// generating the log message.
		/// 
		/// Function must be a static string, such as the value of
		/// the __FUNCTION__ macro. The string is not copied
		/// internally for performance reasons.
	
	const char* getSourceFunction() const;
	///  Returns the source function of the code creating the
	/// message. May be 0 if not set.
	
	void setSourceLine(int line);
		/// Sets the source file line of the statement
		/// generating the log message.
		///
		/// This is usually the result of the __LINE__
		/// macro.

	int getSourceLine() const;
		/// Returns the source file line of the statement
		/// generating the log message. May be 0
		/// if not set.

	bool has(const std::string& param) const;
		/// Returns true if a parameter with the given name exists.

	const std::string& get(const std::string& param) const;
		/// Returns a const reference to the value of the parameter
		/// with the given name. Throws a NotFoundException if the
		/// parameter does not exist.

	const std::string& get(const std::string& param, const std::string& defaultValue) const;
		/// Returns a const reference to the value of the parameter
		/// with the given name. If the parameter with the given name
		/// does not exist, then defaultValue is returned.

	const StringMap& getAll() const;
		/// Returns a const reference to all the values

	void set(const std::string& param, const std::string& value);
		/// Sets the value for a parameter. If the parameter does
		/// not exist, then it is created.

	const std::string& operator [] (const std::string& param) const;
		/// Returns a const reference to the value of the parameter
		/// with the given name. Throws a NotFoundException if the
		/// parameter does not exist.

	std::string& operator [] (const std::string& param);
		/// Returns a reference to the value of the parameter with the
		/// given name. This can be used to set the parameter's value.
		/// If the parameter does not exist, it is created with an
		/// empty string value.

protected:
	void init();

private:
	std::string _source;
	std::string _text;
	Priority    _prio;
	Timestamp   _time;
	long        _tid;
	long        _ostid;
	std::string _thread;
	long        _pid;

#ifdef POCO_ENABLE_SOURCE_LOCATION
	std::source_location _srcLocation;
#endif

	const char* _file;
	const char* _function;
	int         _line;
	StringMap*  _pMap;
};


//
// inlines
//
inline const std::string& Message::getSource() const
{
	return _source;
}


inline const std::string& Message::getText() const
{
	return _text;
}


inline Message::Priority Message::getPriority() const
{
	return _prio;
}


inline const Timestamp& Message::getTime() const
{
	return _time;
}


inline const std::string& Message::getThread() const
{
	return _thread;
}


inline long Message::getTid() const
{
	return _tid;
}

inline long Message::getOsTid() const
{
	return _ostid;
}

inline long Message::getPid() const
{
	return _pid;
}


inline const char* Message::getSourceFile() const
{
	return _file;
}


inline const char* Message::getSourceFunction() const
{
	return _function;
}


inline int Message::getSourceLine() const
{
	return _line;
}


inline void swap(Message& m1, Message& m2) noexcept
{
	m1.swap(m2);
}


} // namespace Poco


#endif // Foundation_Message_INCLUDED
