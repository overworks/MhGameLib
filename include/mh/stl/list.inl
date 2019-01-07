template<typename Elem, typename Allocator>
inline list<Elem, Allocator>::list( const Allocator& allocator )
	:	m_capacity( 0 )
	,	m_size( 0 )
{
}

template<typename Elem, typename Allocator>
inline list<Elem, Allocator>::list( typename list<Elem, Allocator>::size_type n, const Elem& value, const Allocator& allocator )
{
	allocator_type::rebind<LinkNode>::other real_allocator;
	m_head = real_allocator.allocate( n );
	LinkNode* prev = m_head;
	LinkNode* next = NULL;
	for( size_type i = 0; i < n; ++i )
	{
		real_allocator.construct( next, ListNode( value, prev, next ) );
	}
}

template<typename Elem, typename Allocator>
inline list<Elem, Allocator>::~list()
{}

template<typename T, typename A>
inline bool list<T, A>::empty() const
{
	return ( m_size == 0 );
}

template<typename T, typename A>
inline typename list<T, A>::size_type list<T, A>::size() const
{
	return m_size;
}

template<typename T, typename A>
inline typename list<T, A>::size_type list<T, A>::max_size() const
{
	return real_allocator_type().max_size();
}

template<typename T, typename A>
inline void swap( list<T, A>& l, list<T, A>& r )
{
	l.swap( r );
}