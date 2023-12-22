//
// Array.h
//
// Library: Foundation
// Package: Core
// Module:  Array
//
// Definition of the Array class
//
// Copyright (c) 2004-2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//
// ------------------------------------------------------------------------------
// (C) Copyright Nicolai M. Josuttis 2001.
// Permission to copy, use, modify, sell and distribute this software
// is granted provided this copyright notice appears in all copies.
// This software is provided "as is" without express or implied
// warranty, and with no claim as to its suitability for any purpose.
// ------------------------------------------------------------------------------


#ifndef Foundation_ArrayInline_INCLUDED
#define Foundation_ArrayInline_INCLUDED

#if defined(POCO_MODULES)
import std;
import poco.foundation;
#else
#include "Poco/Array.h"
#include <algorithm>
#endif

namespace Poco {

// comparisons
template<class T, std::size_t N>
 bool operator== (const Array<T, N>& x, const Array<T, N>& y)
{
	return std::equal(x.begin(), x.end(), y.begin());
}

template<class T, std::size_t N>
inline  bool operator< (const Array<T, N>& x, const Array<T, N>& y)
{
	return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}


template<class T, std::size_t N>
inline  bool operator!= (const Array<T, N>& x, const Array<T, N>& y)
{
	return !(x == y);
}


template<class T, std::size_t N>
inline  bool operator> (const Array<T, N>& x, const Array<T, N>& y)
{
	return y < x;
}


template<class T, std::size_t N>
inline  bool operator<= (const Array<T, N>& x, const Array<T, N>& y)
{
	return !(y < x);
}


template<class T, std::size_t N>
inline  bool operator>= (const Array<T, N>& x, const Array<T, N>& y)
{
	return !(x < y);
}


template<class T, std::size_t N>
inline  void swap(Array<T, N>& x, Array<T, N>& y) noexcept
/// global swap()
{
	x.swap(y);
}


}// namespace Poco


#endif // Foundation_Array_INCLUDED

