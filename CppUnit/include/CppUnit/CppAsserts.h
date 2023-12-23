//
// CppAsserts.h
//


#ifndef CppUnit_CppAsserts_INCLUDED
#define CppUnit_CppAsserts_INCLUDED

// A set of macros which allow us to get the line number
// and file name at the point of an error.
// Just goes to show that preprocessors do have some
// redeeming qualities.

// for backward compatibility only
// (may conflict with C assert, use at your own risk)
#undef assert
#define assert(condition) \
	(this->assertImplementation((condition), (#condition), __LINE__, __FILE__))

#define assertTrue(condition) \
	(this->assertImplementation((condition), (#condition), __LINE__, __FILE__))

#define assertFalse(condition) \
	(this->assertImplementation(!(condition), (#condition), __LINE__, __FILE__))

#define loop_1_assert(data1line, condition) \
	(this->loop1assertImplementation((condition), (#condition), __LINE__, data1line, __FILE__))

#define loop_2_assert(data1line, data2line, condition) \
	(this->loop2assertImplementation((condition), (#condition), __LINE__, data1line, data2line, __FILE__))

#define assertEqualDelta(expected, actual, delta) \
	(this->assertEquals((expected), (actual), (delta), __LINE__, __FILE__))

#define assertEqual(expected, actual) \
	(this->assertEquals((expected), (actual), __LINE__, __FILE__))

#define assertNullPtr(ptr) \
	(this->assertNull((ptr), #ptr, __LINE__, __FILE__))

#define assertNotNullPtr(ptr) \
	(this->assertNotNull((ptr), #ptr, __LINE__, __FILE__))

#define failmsg(msg) \
	(this->fail(msg, __LINE__, __FILE__))

#define warnmsg(msg) \
	(this->fail(msg, __LINE__, __FILE__))

#endif
