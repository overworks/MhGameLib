#ifndef	_MH_STL_MEMORY_INL_
#define	_MH_STL_MEMORY_INL_

/*
 *	이하 auto_ptr 구현
 */
template<typename T>
inline auto_ptr<T>::auto_ptr( T* p ) throw()
	:	m_ptr( p )
{
}

template<typename T>
inline auto_ptr<T>::auto_ptr( auto_ptr<T>& r ) throw()
	:	m_ptr( r.release() )
{
}

template<typename T> template<typename U>
inline auto_ptr<T>::auto_ptr( auto_ptr<U>& r ) throw()
	:	m_ptr( r.release() )
{
}

template<typename T>
inline auto_ptr<T>::auto_ptr( auto_ptr_ref<T> r ) throw()
{
	m_ptr = r.ref;
	r.ref = 0;
}

template<typename T>
inline auto_ptr<T>::~auto_ptr() throw()
{
	delete m_ptr;
}

template<typename T> template<typename U>
inline auto_ptr<T>::operator auto_ptr<U>() throw()
{
	return auto_ptr<U>( *this );
}

template<typename T> template<typename U>
inline auto_ptr<T>::operator auto_ptr_ref<U>() throw()
{
	U* temp = m_ptr;	// 암시적 변환 테스트
	auto_ptr_ref<U> result( temp );
	m_ptr = 0;
	return result;
}


template<typename T>
inline T* auto_ptr<T>::get() const throw()
{
	return m_ptr;
}

template<typename T>
inline T* auto_ptr<T>::release() throw()
{
	T* temp = m_ptr;
	m_ptr = 0;
	return temp;
}

template<typename T>
inline void auto_ptr<T>::reset( T* p ) throw()
{
	if( p != m_ptr )
		delete m_ptr;
	m_ptr = p;
}

template<typename T>
inline T& auto_ptr<T>::operator * () const throw()
{
	return *get();
}

template<typename T>
inline T* auto_ptr<T>::operator -> () const throw()
{
	return get();
}

template<typename T>
inline auto_ptr<T>& auto_ptr<T>::operator = ( auto_ptr<T>& r ) throw()
{
	reset( r.release() );
	return *this;
}

template<typename T> template<typename U>
inline auto_ptr<T>& auto_ptr<T>::operator = ( auto_ptr<U>& r ) throw()
{
	reset( r.release() );
	return *this;
}

template<typename T>
inline auto_ptr<T>& auto_ptr<T>::operator = ( auto_ptr_ref<T> r ) throw()
{
	T* temp = r.ref;
	r.ref = 0;
	reset( temp );
	return *this;
}





#endif	// _MH_STL_MEMORY_INL_