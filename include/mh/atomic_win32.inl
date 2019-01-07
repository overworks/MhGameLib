#ifndef _MH_ATOMIC_WIN32_INL_
#define	_MH_ATOMIC_WIN32_INL_

namespace Mh
{
	// 이하 native_atomic 멤버
	template <class T>
	native_atomic<T>::native_atomic(T v)
		:	m_field(v)
	{
	}

	template <class T>
	template <ordering_constraint c>
	void native_atomic<T>::store(const T& v)
	{
		m_field = v;
	}

	template <class T>
	template <ordering_constraint c>
	T native_atomic<T>::load()
	{
		return m_field;
	}

	template <class T>
	bool native_atomic<T>::basics_supported()
	{
		return true;
	}

	// atomic_scalar 멤버
	template<typename T>
	size_t atomic_scalar<T>::size = sizeof(T);

}		// namespace Mh

#endif	/* _MH_ATOMIC_WIN32_INL_ */