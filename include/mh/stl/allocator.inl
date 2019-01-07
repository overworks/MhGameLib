template<typename T>
allocator<T>::allocator()
{}

template<typename T>
allocator<T>::allocator( const allocator<T>& allocator )
{}

template<typename T>
template<typename U>
allocator<T>::allocator( const allocator<U>& allocator )
{}

template<typename T>
allocator<T>::~allocator()
{
	// dump all memory info in this
	// 여기서 해제되지 않은 모든 메모리 정보를 쏟아냄
}

template<typename T>
inline typename allocator<T>::pointer
allocator<T>::address( typename allocator<T>::reference r )
{
	return &r;
}

template<typename T>
inline typename allocator<T>::const_pointer
allocator<T>::address( typename allocator<T>::const_reference r )
{
	return &r;
}

template<typename T>
inline typename allocator<T>::size_type
allocator<T>::max_size()
{
	return nemuric_limits<size_t>::max() / sizeof(T);
}

template<typename T>
inline typename allocator<T>::pointer
allocator<T>::allocate( typename allocator<T>::size_type n, const void* hint )
{
	return (pointer)( ::operator new( n * sizeof(T) ) );
}

template<typename T>
inline void
allocator<T>::deallocate( typename allocator<T>::pointer p, typename allocator<T>::size_type num )
{
	::operator delete( (void*)p );
}

template<typename T>
inline void
allocator<T>::construct( typename allocator<T>::pointer p, const T& value )
{
	new((void*)p) T(value);
}

template<typename T>
inline void
allocator<T>::destroy( typename allocator<T>::pointer p )
{
	p->~T();
}

template <class T1, class T2>
inline bool operator==(const allocator<T1>&, const allocator<T2>&)
{
	return true;
}

template <class T1, class T2>
inline bool operator!=(const allocator<T1>&, const allocator<T2>&)
{
	return false;
}