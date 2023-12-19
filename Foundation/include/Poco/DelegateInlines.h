//
// Delegate.h
//
// Library: Foundation
// Package: Events
// Module:  Delegate
//
// Implementation of the Delegate template.
//
// Copyright (c) 2006-2011, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_DelegateInlines_INCLUDED
#define Foundation_DelegateInlines_INCLUDED

import poco.foundation;

namespace Poco {

template <class TObj>
inline Poco::Delegate<TObj, void, true> delegate(TObj* pObj, void (TObj::*NotifyMethod)(const void*))
{
	return Delegate<TObj, void, true>(pObj, NotifyMethod);
}


template <class TObj>
inline Poco::Delegate<TObj, void, false> delegate(TObj* pObj, void (TObj::*NotifyMethod)())
{
	return Delegate<TObj, void, false>(pObj, NotifyMethod);
}


template <class TObj>
inline Poco::Expire<void> delegate(TObj* pObj, void (TObj::*NotifyMethod)(const void*), Timestamp::TimeDiff expireMillisecs)
{
	return Expire<void>(Delegate<TObj, void, true>(pObj, NotifyMethod), expireMillisecs);
}


template <class TObj>
inline Poco::Expire<void> delegate(TObj* pObj, void (TObj::*NotifyMethod)(), Timestamp::TimeDiff expireMillisecs)
{
	return Expire<void>(Delegate<TObj, void, false>(pObj, NotifyMethod), expireMillisecs);
}


inline Poco::Expire<void> delegate(void (*NotifyMethod)(const void*), Timestamp::TimeDiff expireMillisecs)
{
	return Poco::Expire<void>(Poco::FunctionDelegate<void, true, true>(NotifyMethod), expireMillisecs);
}


inline Poco::Expire<void> delegate(void (*NotifyMethod)(void*), Timestamp::TimeDiff expireMillisecs)
{
	return Poco::Expire<void>(Poco::FunctionDelegate<void, true, false>(NotifyMethod), expireMillisecs);
}


inline Poco::Expire<void> delegate(void (*NotifyMethod)(), Timestamp::TimeDiff expireMillisecs)
{
	return Poco::Expire<void>(Poco::FunctionDelegate<void, false>(NotifyMethod), expireMillisecs);
}


inline Poco::FunctionDelegate<void, true, true> delegate(void (*NotifyMethod)(const void*))
{
	return Poco::FunctionDelegate<void, true, true>(NotifyMethod);
}


inline Poco::FunctionDelegate<void, true, false> delegate(void (*NotifyMethod)(void*))
{
	return Poco::FunctionDelegate<void, true, false>(NotifyMethod);
}


inline Poco::FunctionDelegate<void, false> delegate(void (*NotifyMethod)())
{
	return Poco::FunctionDelegate<void, false>(NotifyMethod);
}


} // namespace Poco


#endif // Foundation_Delegate_INCLUDED
