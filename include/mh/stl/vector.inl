template<typename T, typename A>
vector<T, A>::vector( const A& allocator )
	:	m_buffer( NULL ), m_size( 0 ), m_capacity( 0 ), m_allocator( allocator )
{}

template<typename T, typename A>
vector<T, A>::vector( size_type n, const T& value, const A& allocator )
	:	m_allocator( allocator )
{
	m_buffer = m_allocator.allocate( n );
	for( size_type i = 0; i < n; ++i )
		m_allocator.construct( m_buffer[i], n );

	m_size = n;
	m_capacity = n;
}

template<typename T, typename A>
template<typename I>
vector<T, A>::vector( I first, I last, const A& allocator )
	:	m_allocator( allocator )
{
	assign( first, last );
}

template<typename T, typename A>
vector<T, A>::vector( const vector<T, A>& x )
{
}

template<typename T, typename A>
vector<T, A>::~vector()
{
	if( NULL != m_buffer )
	{
		m_allocator.deallocate( m_buffer, m_capacity );
	}
}

template<typename T, typename A>
template<typename I>
void vector<T, A>::assign( I first, I last )
{
	clear();
	m_size = last - first;
	m_capacity = m_size;
	m_buffer = m_allocator.allocate( m_size, NULL );
	copy( first, last, m_buffer );
}

template<typename T, typename A>
void vector<T, A>::assign( typename vector<T, A>::size_type n, const T& u )
{
	clear();
	m_buffer = m_allocator.allocate( n );
	for( size_type i = 0; i < n; ++i )
		m_allocate.construct( m_buffer + i, u );
	m_capacity = m_size = n;
}
#if 0
template<typename T, typename A>
iterator Vector<T, A>::insert( typename Vector<T, A>::iterator position, const T& x )
{
	if( size() == capacity() )
		reserve( size() * 2 );

	// 특정 위치에서 한칸씩 옮김
	memmove( position + 1, position, sizeof(T) * (end() - position) );
	*position = x;
}

template<typename T, typename A>
void Vector<T, A>::insert( iterator position, size_type n, const T& x )
{
	if( n > capacity() - size() )
		reserve( size() * 2 );
}
#endif

template<typename T, typename A>
void vector<T, A>::pop_back()
{
	if( m_size > 0 )
	{
		m_allocator.destroy( m_buffer + m_size );
		--m_size;
	}
}

template<typename T, typename A>
void vector<T, A>::push_back( const T& x )
{
	if( m_size == m_capacity )
	{
		// 2배로 늘려서 할당
		T* temp = m_allocator.allocate( m_capacity * 2 );
		copy( temp, begin(), end() );
		m_allocator.deallocate( m_buffer, m_capacity );
		m_capacity = m_capacity * 2;
		m_buffer = temp;
	}
	*(begin() + size()) = x;
	m_size++;
}

template<typename T, typename A>
void vector<T, A>::reserve( typename vector<T, A>::size_type n )
{
	if( n <= capacity() )
		return;

	pointer const buffer = m_allocator.allocate( n, NULL );
	if( size() > 0 )
	{
		copy( buffer, begin(), end() );
		for_each( begin(), end(), m_allocator.destroy() );
		m_allocator.deallocate( m_buffer );
	}
	m_capacity = n;
	m_buffer = buffer;
}

template<typename T, typename A>
inline void vector<T, A>::resize( typename vector<T, A>::size_type sz, T c )
{
	if( sz > size() )
		insert( end(), n - size(), c );
	else if( sz < size() )
		erase( begin() + n, end() );
}

#if 0
template<typename T, typename A>
void Vector<T, A>::swap( Vector<T, A>& vec );
{
	// 카피 말고 move를 이용...
	Vector<T, A> temp( vec );
}
#endif



template<typename T, typename A>
void vector<T, A>::clear()
{
	if( NULL != m_buffer )
		m_allocator.deallocate( m_buffer, m_capacity );

	m_capacity = 0;
	m_size = 0;
}

template<typename T, typename A>
inline bool vector<T, A>::empty() const
{
	return (0 != size());
}

template<typename T, typename A>
inline typename vector<T, A>::reference vector<T, A>::at( typename vector<T, A>::size_type n )
{
	return m_buffer[n];
}

template<typename T, typename A>
inline typename vector<T, A>::size_type vector<T, A>::size() const
{
	return m_size;
}

template<typename T, typename A>
inline typename vector<T, A>::size_type vector<T, A>::capacity() const
{
	return m_capacity;
}

template<typename T, typename A>
inline typename vector<T, A>::size_type vector<T, A>::max_size() const
{
	return m_allocator.max_size();
}

template<typename T, typename A>
inline typename vector<T, A>::allocator_type vector<T, A>::get_allocator() const
{
	return m_allocator;
}

template<typename T, typename A>
inline vector<T, A>& vector<T, A>::operator = ( const vector<T, A>& x )
{
	clear();
	m_allocator = x.m_allocator;
	m_capacity = m_size = x.m_size;
	m_buffer = m_allocator.allocate( m_size, NULL );
	copy( m_buffer, x.begin(), x.end() );
	return (*this);
}

template<typename T, typename A>
inline typename vector<T, A>::reference vector<T, A>::operator [] ( typename vector<T, A>::size_type n )
{
	return *(begin() + n);
}

template<typename T, typename A>
inline typename vector<T, A>::const_reference vector<T, A>::operator [] ( typename vector<T, A>::size_type n ) const
{
	return *(begin() + n);
}

template<typename T, typename A>
inline void swap( vector<T, A>& l, vector<T, A>& r )
{
	l.swap( r );
}