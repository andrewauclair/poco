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

#if defined(POCO_MODULES)
import poco.foundation;
#else
#include "Poco/Delegate.h"
#include "Poco/PriorityExpire.h"
#include "Poco/PriorityDelegate.h"
#include "Poco/FunctionDelegate.h"
#include "Poco/FunctionPriorityDelegate.h"
#endif

namespace Poco {

	template <class TObj, class TArgs>
	inline Delegate<TObj, TArgs, true> delegate(TObj* pObj, void (TObj::* NotifyMethod)(const void*, TArgs&))
	{
		return Delegate<TObj, TArgs, true>(pObj, NotifyMethod);
	}


	template <class TObj, class TArgs>
	inline Delegate<TObj, TArgs, false> delegate(TObj* pObj, void (TObj::* NotifyMethod)(TArgs&))
	{
		return Delegate<TObj, TArgs, false>(pObj, NotifyMethod);
	}


	template <class TObj, class TArgs>
	inline Expire<TArgs> delegate(TObj* pObj, void (TObj::* NotifyMethod)(const void*, TArgs&), Timestamp::TimeDiff expireMillisecs)
	{
		return Expire<TArgs>(Delegate<TObj, TArgs, true>(pObj, NotifyMethod), expireMillisecs);
	}


	template <class TObj, class TArgs>
	inline Expire<TArgs> delegate(TObj* pObj, void (TObj::* NotifyMethod)(TArgs&), Timestamp::TimeDiff expireMillisecs)
	{
		return Expire<TArgs>(Delegate<TObj, TArgs, false>(pObj, NotifyMethod), expireMillisecs);
	}


	template <class TArgs>
	inline Expire<TArgs> delegate(void (*NotifyMethod)(const void*, TArgs&), Timestamp::TimeDiff expireMillisecs)
	{
		return Expire<TArgs>(FunctionDelegate<TArgs, true, true>(NotifyMethod), expireMillisecs);
	}


	template <class TArgs>
	inline Expire<TArgs> delegate(void (*NotifyMethod)(void*, TArgs&), Timestamp::TimeDiff expireMillisecs)
	{
		return Expire<TArgs>(FunctionDelegate<TArgs, true, false>(NotifyMethod), expireMillisecs);
	}


	template <class TArgs>
	inline Expire<TArgs> delegate(void (*NotifyMethod)(TArgs&), Timestamp::TimeDiff expireMillisecs)
	{
		return Expire<TArgs>(FunctionDelegate<TArgs, false>(NotifyMethod), expireMillisecs);
	}


	template <class TArgs>
	inline FunctionDelegate<TArgs, true, true> delegate(void (*NotifyMethod)(const void*, TArgs&))
	{
		return FunctionDelegate<TArgs, true, true>(NotifyMethod);
	}


	template <class TArgs>
	inline FunctionDelegate<TArgs, true, false> delegate(void (*NotifyMethod)(void*, TArgs&))
	{
		return FunctionDelegate<TArgs, true, false>(NotifyMethod);
	}


	template <class TArgs>
	inline FunctionDelegate<TArgs, false> delegate(void (*NotifyMethod)(TArgs&))
	{
		return FunctionDelegate<TArgs, false>(NotifyMethod);
	}

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

template <class TObj, class TArgs>
static PriorityDelegate<TObj, TArgs, true> priorityDelegate(TObj* pObj, void (TObj::* NotifyMethod)(const void*, TArgs&), int prio)
{
	return PriorityDelegate<TObj, TArgs, true>(pObj, NotifyMethod, prio);
}


template <class TObj, class TArgs>
static PriorityDelegate<TObj, TArgs, false> priorityDelegate(TObj* pObj, void (TObj::* NotifyMethod)(TArgs&), int prio)
{
	return PriorityDelegate<TObj, TArgs, false>(pObj, NotifyMethod, prio);
}


template <class TObj, class TArgs>
static PriorityExpire<TArgs> priorityDelegate(TObj* pObj, void (TObj::* NotifyMethod)(const void*, TArgs&), int prio, Timestamp::TimeDiff expireMilliSec)
{
	return PriorityExpire<TArgs>(PriorityDelegate<TObj, TArgs, true>(pObj, NotifyMethod, prio), expireMilliSec);
}


template <class TObj, class TArgs>
static PriorityExpire<TArgs> priorityDelegate(TObj* pObj, void (TObj::* NotifyMethod)(TArgs&), int prio, Timestamp::TimeDiff expireMilliSec)
{
	return PriorityExpire<TArgs>(PriorityDelegate<TObj, TArgs, false>(pObj, NotifyMethod, prio), expireMilliSec);
}


template <class TArgs>
static PriorityExpire<TArgs> priorityDelegate(void (*NotifyMethod)(const void*, TArgs&), int prio, Timestamp::TimeDiff expireMilliSec)
{
	return PriorityExpire<TArgs>(FunctionPriorityDelegate<TArgs, true, true>(NotifyMethod, prio), expireMilliSec);
}


template <class TArgs>
static PriorityExpire<TArgs> priorityDelegate(void (*NotifyMethod)(void*, TArgs&), int prio, Timestamp::TimeDiff expireMilliSec)
{
	return PriorityExpire<TArgs>(FunctionPriorityDelegate<TArgs, true, false>(NotifyMethod, prio), expireMilliSec);
}


template <class TArgs>
static PriorityExpire<TArgs> priorityDelegate(void (*NotifyMethod)(TArgs&), int prio, Timestamp::TimeDiff expireMilliSec)
{
	return PriorityExpire<TArgs>(FunctionPriorityDelegate<TArgs, false>(NotifyMethod, prio), expireMilliSec);
}


template <class TArgs>
static FunctionPriorityDelegate<TArgs, true, true> priorityDelegate(void (*NotifyMethod)(const void*, TArgs&), int prio)
{
	return FunctionPriorityDelegate<TArgs, true, true>(NotifyMethod, prio);
}


template <class TArgs>
static FunctionPriorityDelegate<TArgs, true, false> priorityDelegate(void (*NotifyMethod)(void*, TArgs&), int prio)
{
	return FunctionPriorityDelegate<TArgs, true, false>(NotifyMethod, prio);
}


template <class TArgs>
static FunctionPriorityDelegate<TArgs, false> priorityDelegate(void (*NotifyMethod)(TArgs&), int prio)
{
	return FunctionPriorityDelegate<TArgs, false>(NotifyMethod, prio);
}


template <class TObj>
static PriorityDelegate<TObj, void, true> priorityDelegate(TObj* pObj, void (TObj::* NotifyMethod)(const void*), int prio)
{
	return PriorityDelegate<TObj, void, true>(pObj, NotifyMethod, prio);
}


template <class TObj>
static PriorityDelegate<TObj, void, false> priorityDelegate(TObj* pObj, void (TObj::* NotifyMethod)(), int prio)
{
	return PriorityDelegate<TObj, void, false>(pObj, NotifyMethod, prio);
}


template <class TObj>
static PriorityExpire<void> priorityDelegate(TObj* pObj, void (TObj::* NotifyMethod)(const void*), int prio, Timestamp::TimeDiff expireMilliSec)
{
	return PriorityExpire<void>(PriorityDelegate<TObj, void, true>(pObj, NotifyMethod, prio), expireMilliSec);
}


template <class TObj>
static PriorityExpire<void> priorityDelegate(TObj* pObj, void (TObj::* NotifyMethod)(), int prio, Timestamp::TimeDiff expireMilliSec)
{
	return PriorityExpire<void>(PriorityDelegate<TObj, void, false>(pObj, NotifyMethod, prio), expireMilliSec);
}


inline PriorityExpire<void> priorityDelegate(void (*NotifyMethod)(const void*), int prio, Timestamp::TimeDiff expireMilliSec)
{
	return PriorityExpire<void>(FunctionPriorityDelegate<void, true, true>(NotifyMethod, prio), expireMilliSec);
}


inline PriorityExpire<void> priorityDelegate(void (*NotifyMethod)(void*), int prio, Timestamp::TimeDiff expireMilliSec)
{
	return PriorityExpire<void>(FunctionPriorityDelegate<void, true, false>(NotifyMethod, prio), expireMilliSec);
}


inline PriorityExpire<void> priorityDelegate(void (*NotifyMethod)(), int prio, Timestamp::TimeDiff expireMilliSec)
{
	return PriorityExpire<void>(FunctionPriorityDelegate<void, false>(NotifyMethod, prio), expireMilliSec);
}


inline FunctionPriorityDelegate<void, true, true> priorityDelegate(void (*NotifyMethod)(const void*), int prio)
{
	return FunctionPriorityDelegate<void, true, true>(NotifyMethod, prio);
}


inline FunctionPriorityDelegate<void, true, false> priorityDelegate(void (*NotifyMethod)(void*), int prio)
{
	return FunctionPriorityDelegate<void, true, false>(NotifyMethod, prio);
}


inline FunctionPriorityDelegate<void, false> priorityDelegate(void (*NotifyMethod)(), int prio)
{
	return FunctionPriorityDelegate<void, false>(NotifyMethod, prio);
}
} // namespace Poco


#endif // Foundation_Delegate_INCLUDED
