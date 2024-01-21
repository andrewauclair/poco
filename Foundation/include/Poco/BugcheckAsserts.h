#ifndef BUGCHECK_ASSERTS_H
#define BUGCHECK_ASSERTS_H

//
// useful macros (these automatically supply line number and file name)
//
#if defined(__KLOCWORK__) || defined(__clang_analyzer__)


// Short-circuit these macros when under static analysis.
// Ideally, static analysis tools should understand and reason correctly about
// noreturn methods such as Bugcheck::bugcheck(). In practice, they don't.
// Help them by turning these macros into std::abort() as described here:
// https://developer.klocwork.com/documentation/en/insight/10-1/tuning-cc-analysis#Usingthe__KLOCWORK__macro

#include <cstdlib> // for abort
#define poco_assert_dbg(cond)           do { if (!(cond)) std::abort(); } while (0)
#define poco_assert_msg_dbg(cond, text) do { if (!(cond)) std::abort(); } while (0)
#define poco_assert(cond)               do { if (!(cond)) std::abort(); } while (0)
#define poco_assert_msg(cond, text)     do { if (!(cond)) std::abort(); } while (0)
#define poco_check_ptr(ptr)             do { if (!(ptr)) std::abort(); } while (0)
#define poco_bugcheck()                 do { std::abort(); } while (0)
#define poco_bugcheck_msg(msg)          do { std::abort(); } while (0)


#else // defined(__KLOCWORK__) || defined(__clang_analyzer__)


#if defined(_DEBUG)
#define poco_assert_dbg(cond) \
		if (!(cond)) Poco::Bugcheck::assertion(#cond, __FILE__, __LINE__); else (void) 0

#define poco_assert_msg_dbg(cond, text) \
		if (!(cond)) Poco::Bugcheck::assertion(#cond, __FILE__, __LINE__, text); else (void) 0
#else
#define poco_assert_msg_dbg(cond, text)
#define poco_assert_dbg(cond)
#endif


#define poco_assert(cond) \
	if (!(cond)) Poco::Bugcheck::assertion(#cond, __FILE__, __LINE__); else (void) 0


#define poco_assert_msg(cond, text) \
	if (!(cond)) Poco::Bugcheck::assertion(#cond, __FILE__, __LINE__, text); else (void) 0


#define poco_check_ptr(ptr) \
	if (!(ptr)) Poco::Bugcheck::nullPointer(#ptr, __FILE__, __LINE__); else (void) 0


#define poco_bugcheck() \
	Poco::Bugcheck::bugcheck(__FILE__, __LINE__)


#define poco_bugcheck_msg(msg) \
	Poco::Bugcheck::bugcheck(msg, __FILE__, __LINE__)


#endif // defined(__KLOCWORK__) || defined(__clang_analyzer__)


#define poco_unexpected() \
	Poco::Bugcheck::unexpected(__FILE__, __LINE__);


#define poco_debugger() \
	Poco::Bugcheck::debugger(__FILE__, __LINE__)


#define poco_debugger_msg(msg) \
	Poco::Bugcheck::debugger(msg, __FILE__, __LINE__)


#if defined(_DEBUG)
#	define poco_stdout_dbg(outstr) \
	std::cout << __FILE__ << '(' << std::dec << __LINE__ << "):" << outstr << std::endl;
#else
#	define poco_stdout_dbg(outstr)
#endif


#if defined(_DEBUG)
#	define poco_stderr_dbg(outstr) \
		std::cerr << __FILE__ << '(' << std::dec << __LINE__ << "):" << outstr << std::endl;
#else
#	define poco_stderr_dbg(outstr)




#if defined(__GNUC__) && (__GNUC__ == 3) && ((__GNUC_MINOR__ == 3) || (__GNUC_MINOR__ == 4))
#define poco_static_assert(B) \
	typedef char POCO_JOIN(poco_static_assert_typedef_, __LINE__) \
        [POCO_STATIC_ASSERTION_FAILURE<(bool) (B)>::value]
#else
#define poco_static_assert(B) \
	typedef poco_static_assert_test<sizeof(POCO_STATIC_ASSERTION_FAILURE<(bool) (B)>)> \
		POCO_JOIN(poco_static_assert_typedef_, __LINE__) POCO_UNUSED
#endif

#endif
#endif
