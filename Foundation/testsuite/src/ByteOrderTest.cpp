//
// ByteOrderTest.cpp
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "ByteOrderTest.h"

#include "CppUnit/CppAsserts.h"
#include "CppUnit/CppTestMacros.h"

#if defined(POCO_MODULES)
import poco.cppunit;
import poco.foundation;
#else
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/ByteOrder.h"
#endif

ByteOrderTest::ByteOrderTest(const std::string& name): CppUnit::TestCase(name)
{
}


ByteOrderTest::~ByteOrderTest()
{
}


void ByteOrderTest::testByteOrderFlip()
{
	{
		Poco::Int16 norm = (Poco::Int16) 0xAABB;
		Poco::Int16 flip = Poco::ByteOrder::flipBytes(norm);
		assertTrue (Poco::UInt16(flip) == 0xBBAA);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (flip == norm);
	}
	{
		Poco::UInt16 norm = (Poco::UInt16) 0xAABB;
		Poco::UInt16 flip = Poco::ByteOrder::flipBytes(norm);
		assertTrue (flip == 0xBBAA);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (flip == norm);
	}
	{
		Poco::Int32 norm = 0xAABBCCDD;
		Poco::Int32 flip = Poco::ByteOrder::flipBytes(norm);
		assertTrue (Poco::UInt32(flip) == 0xDDCCBBAA);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (flip == norm);
	}
	{
		Poco::UInt32 norm = 0xAABBCCDD;
		Poco::UInt32 flip = Poco::ByteOrder::flipBytes(norm);
		assertTrue (flip == 0xDDCCBBAA);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (flip == norm);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Poco::Int64 norm = (Poco::Int64(0x8899AABB) << 32) + 0xCCDDEEFF;
		Poco::Int64 flip = Poco::ByteOrder::flipBytes(norm);
		assertTrue (flip == (Poco::Int64(0xFFEEDDCC) << 32) + 0xBBAA9988);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (flip == norm);
	}
	{
		Poco::UInt64 norm = (Poco::UInt64(0x8899AABB) << 32) + 0xCCDDEEFF;
		Poco::UInt64 flip = Poco::ByteOrder::flipBytes(norm);
		assertTrue (flip == (Poco::UInt64(0xFFEEDDCC) << 32) + 0xBBAA9988);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (flip == norm);
	}
	#endif
}


void ByteOrderTest::testByteOrderBigEndian()
{
#if defined(POCO_ARCH_BIG_ENDIAN)
	//
	// big-endian systems
	//
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::toBigEndian(norm);
		assertTrue (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::toBigEndian(norm);
		assertTrue (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::toBigEndian(norm);
		assertTrue (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::toBigEndian(norm);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::toBigEndian(norm);
		assertTrue (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::toBigEndian(norm);
		assertTrue (norm == flip);
	}
	#endif

	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::fromBigEndian(norm);
		assertTrue (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::fromBigEndian(norm);
		assertTrue (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::fromBigEndian(norm);
		assertTrue (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::fromBigEndian(norm);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::fromBigEndian(norm);
		assertTrue (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::fromBigEndian(norm);
		assertTrue (norm == flip);
	}
	#endif
#else
	//
	// little-endian systems
	//
	{
		Poco::Int16 norm = 4;
		Poco::Int16 flip = Poco::ByteOrder::toBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt16 norm = 4;
		Poco::UInt16 flip = Poco::ByteOrder::toBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::Int32 norm = 4;
		Poco::Int32 flip = Poco::ByteOrder::toBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt32 norm = 4;
		Poco::UInt32 flip = Poco::ByteOrder::toBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Poco::Int64 norm = 4;
		Poco::Int64 flip = Poco::ByteOrder::toBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt64 norm = 4;
		Poco::UInt64 flip = Poco::ByteOrder::toBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#endif

	{
		Poco::Int16 norm = 4;
		Poco::Int16 flip = Poco::ByteOrder::fromBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt16 norm = 4;
		Poco::UInt16 flip = Poco::ByteOrder::fromBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::Int32 norm = 4;
		Poco::Int32 flip = Poco::ByteOrder::fromBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt32 norm = 4;
		Poco::UInt32 flip = Poco::ByteOrder::fromBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Poco::Int64 norm = 4;
		Poco::Int64 flip = Poco::ByteOrder::fromBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt64 norm = 4;
		Poco::UInt64 flip = Poco::ByteOrder::fromBigEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#endif
#endif
}


void ByteOrderTest::testByteOrderLittleEndian()
{
#if defined(POCO_ARCH_LITTLE_ENDIAN)
	//
	// big-endian systems
	//
	{
		Poco::Int16 norm = 4;
		Poco::Int16 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt16 norm = 4;
		Poco::UInt16 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	{
		Poco::Int32 norm = 4;
		Poco::Int32 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt32 norm = 4;
		Poco::UInt32 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Poco::Int64 norm = 4;
		Poco::Int64 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt64 norm = 4;
		Poco::UInt64 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	#endif

	{
		Poco::Int16 norm = 4;
		Poco::Int16 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt16 norm = 4;
		Poco::UInt16 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	{
		Poco::Int32 norm = 4;
		Poco::Int32 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt32 norm = 4;
		Poco::UInt32 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Poco::Int64 norm = 4;
		Poco::Int64 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt64 norm = 4;
		Poco::UInt64 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm == flip);
	}
	#endif
#else
	//
	// little-endian systems
	//
	{
		Poco::Int16 norm = 4;
		Poco::Int16 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt16 norm = 4;
		Poco::UInt16 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::Int32 norm = 4;
		Poco::Int32 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt32 norm = 4;
		Poco::UInt32 flip = Poco::ByteOrder::toLittleEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::toLittleEndian(norm);
		assertTrue (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::toLittleEndian(norm);
		assertTrue (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#endif

	{
		Poco::Int16 norm = 4;
		Poco::Int16 flip = Poco::ByteOrder::fromLittleEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt16 norm = 4;
		Poco::UInt16 flip = Poco::ByteOrder::fromLittleEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::Int32 norm = 4;
		Poco::Int32 flip = Poco::ByteOrder::fromLittleEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt32 norm = 4;
		Poco::UInt32 flip = Poco::ByteOrder::fromLittleEndian(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::fromLittleEndian(norm);
		assertTrue (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::fromLittleEndian(norm);
		assertTrue (norm != flip);
		flip = ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#endif
#endif
}


void ByteOrderTest::testByteOrderNetwork()
{
#if defined(POCO_ARCH_BIG_ENDIAN)
	//
	// big-endian systems
	//
	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::toNetwork(norm);
		assertTrue (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::toNetwork(norm);
		assertTrue (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::toNetwork(norm);
		assertTrue (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::toNetwork(norm);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::toNetwork(norm);
		assertTrue (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::toNetwork(norm);
		assertTrue (norm == flip);
	}
	#endif

	{
		Int16 norm = 4;
		Int16 flip = ByteOrder::fromNetwork(norm);
		assertTrue (norm == flip);
	}
	{
		UInt16 norm = 4;
		UInt16 flip = ByteOrder::fromNetwork(norm);
		assertTrue (norm == flip);
	}
	{
		Int32 norm = 4;
		Int32 flip = ByteOrder::fromNetwork(norm);
		assertTrue (norm == flip);
	}
	{
		UInt32 norm = 4;
		UInt32 flip = ByteOrder::fromNetwork(norm);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Int64 norm = 4;
		Int64 flip = ByteOrder::fromNetwork(norm);
		assertTrue (norm == flip);
	}
	{
		UInt64 norm = 4;
		UInt64 flip = ByteOrder::fromNetwork(norm);
		assertTrue (norm == flip);
	}
	#endif
#else
	//
	// little-endian systems
	//
	{
		Poco::Int16 norm = 4;
		Poco::Int16 flip = Poco::ByteOrder::toNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt16 norm = 4;
		Poco::UInt16 flip = Poco::ByteOrder::toNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::Int32 norm = 4;
		Poco::Int32 flip = Poco::ByteOrder::toNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt32 norm = 4;
		Poco::UInt32 flip = Poco::ByteOrder::toNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Poco::Int64 norm = 4;
		Poco::Int64 flip = Poco::ByteOrder::toNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt64 norm = 4;
		Poco::UInt64 flip = Poco::ByteOrder::toNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#endif

	{
		Poco::Int16 norm = 4;
		Poco::Int16 flip = Poco::ByteOrder::fromNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt16 norm = 4;
		Poco::UInt16 flip = Poco::ByteOrder::fromNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::Int32 norm = 4;
		Poco::Int32 flip = Poco::ByteOrder::fromNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt32 norm = 4;
		Poco::UInt32 flip = Poco::ByteOrder::fromNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#if defined(POCO_HAVE_INT64)
	{
		Poco::Int64 norm = 4;
		Poco::Int64 flip = Poco::ByteOrder::fromNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	{
		Poco::UInt64 norm = 4;
		Poco::UInt64 flip = Poco::ByteOrder::fromNetwork(norm);
		assertTrue (norm != flip);
		flip = Poco::ByteOrder::flipBytes(flip);
		assertTrue (norm == flip);
	}
	#endif
#endif
}


void ByteOrderTest::setUp()
{
}


void ByteOrderTest::tearDown()
{
}


CppUnit::Test* ByteOrderTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("ByteOrderTest");

	CppUnit_addTest(pSuite, ByteOrderTest, testByteOrderFlip);
	CppUnit_addTest(pSuite, ByteOrderTest, testByteOrderBigEndian);
	CppUnit_addTest(pSuite, ByteOrderTest, testByteOrderLittleEndian);
	CppUnit_addTest(pSuite, ByteOrderTest, testByteOrderNetwork);

	return pSuite;
}
