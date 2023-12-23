//
// CppTestMacros.h
//


#ifndef CppUnit_CppTestMacros_INCLUDED
#define CppUnit_CppTestMacros_INCLUDED

#define CppUnit_addTest(suite, cls, mth) \
	suite->addTest(new CppUnit::TestCaller<cls>(#mth, &cls::mth))

#define CppUnit_addLongTest(suite, cls, mth) \
	suite->addTest(new CppUnit::TestCaller<cls>(#mth, &cls::mth, CppUnit::Test::Long))

#define CppUnit_addQualifiedTest(suite, cls, mth) \
	suite->addTest(new CppUnit::TestCaller<cls>(#cls"::"#mth, &cls::mth))

#define CppUnit_addLongQualifiedTest(suite, cls, mth) \
	suite->addTest(new CppUnit::TestCaller<cls>(#cls"::"#mth, &cls::mth, CppUnit::Test::Long))

#endif
