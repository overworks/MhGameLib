#ifndef _MH_STL_STRING_INL_
#define	_MH_STL_STRING_INL_



template<typename charT, typename charTraits, typename allocator>
basic_string<charT, charTraits, allocator>::basic_string( const allocator& a )
	:	m_allocator( a ), m_internal( NULL )
{}

template<typename charT, typename charTraits, typename allocator>
basic_string<charT, charTraits, allocator>::basic_string( const basic_string& str )
	:	m_allocator( str.m_allocator ), m_internal( str.m_internal )
{
	// 원래는 여기서 락을 걸어야하는데...
	if( m_internal )
	{		
#ifdef	_WIN32
		// 원자적으로 증가
		InterlockedIncrement( &m_internal.ref );
#else
		m_internal.ref++;
#endif
	}
}

template<typename C, typename T, typename A>
inline basic_string<C, T, A>& basic_string<C, T, A>::assign( const basic_string<C, T, A>& str )
{
	clear();
	if( NULL != str.m_interanl )
	{
		m_allocator = str.m_allocator;
		m_internal = str.m_internal;
		++m_interanl.reference;
	}
	return (*this);
}

template<typename C, typename T, typename A>
inline bool basic_string<C, T, A>::empty() const
{
	return ( NULL == m_internal );
}

template<typename C, typename T, typename A>
inline typename basic_string<C, T, A>::size_type
basic_string<C, T, A>::capacity() const
{
	return ( m_internal ? m_internal.length : 0 );
}

template<typename C, typename T, typename A>
inline const C* basic_string<C, T, A>::c_str() const
{
	return ( m_internal ? m_internal.buffer : NULL );
}

template<typename C, typename T, typename A>
inline const C* basic_string<C, T, A>::data() const
{
	return ( m_internal ? m_internal.buffer : NULL );
}

template<typename C, typename T, typename A>
inline typename basic_string<C, T, A>::allocator_type
basic_string<C, T, A>::get_allocator() const
{
	return m_allocator;
}

template<typename C, typename T, typename A>
void basic_string<C, T, A>::clear()
{
	if( m_internal )
	{
		--m_internal.reference;
		if( 0 == m_internal.reference )
		{
			m_allocator.destroy( m_internal );
			m_allocator.deallocate( m_internal, 1 );
		}
		m_internal = NULL;
	}
}

template<typename C, typename T, typename A>
inline basic_string<C, T, A>& basic_string<C, T, A>::operator = ( const basic_string<C, T, A>& str )
{
	return assign( str );
}

template<typename C, typename T, typename A>
inline typename basic_string<C, T, A>::reference
basic_string<C, T, A>::operator [] ( typename basic_string<C, T, A>::size_type n )
{
	return at( n );
}

template<typename C, typename T, typename A>
inline typename basic_string<C, T, A>::const_reference
basic_string<C, T, A>::operator [] ( typename basic_string<C, T, A>::size_type n ) const
{
	return at( n );
}

/*
 *	이하 내부 문자열(C:Char, T:Traits, A:Allocator)
 */
template<typename C, typename T, typename A>
basic_string<C, T, A>::Internal::Internal(const C* str, const A& allocator)
	: allocator(allocator), reference(1), capacity(0)
{
	// str로 NULL이 날아오지 않게 basic_string 에서 처리

	// strlen 이 좋겠지만... 와이드 문자열일 가능성도 있으니 직접 처리
	while (str[length] != 0)
		++length;

	// 할당
	buffer = m_allocator.allocate(C, length + 1);
	memcpy(buffer, str, sizeof(C) * length);
}

template<typename C, typename T, typename A>
basic_string<C, T, A>::Internal::~Internal()
{
	m_allocator.deallocate( buffer, length + 1 );
}

template<typename C, typename T, typename A>
void swap( basic_string<C, T, A>& l, basic_string<C, T, A>& r )
{
	l.swap( r );
}

#endif // !_MH_STL_STRING_INL_
