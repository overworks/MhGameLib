#ifndef _MH_STL_ARRAY_INL_
#define	_MH_STL_ARRAY_INL_

#if		!(_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_CONSTEXPR_)


#else


#endif

// 함수 템플릿 정의
template <typename T, size_t N>
inline typename array<T, N>::reference array<T, N>::at(typename array<T, N>::size_type pos)
{
	if ((pos < 0) || (N <= pos)) throw new std::out_of_range("out of range");
	return arr[pos];
}

template <typename T, size_t N>
inline typename array<T, N>::const_reference array<T, N>::at(typename array<T, N>::size_type pos) const
{
	if ((pos < 0) || (N <= pos)) throw new std::out_of_range("out of range");
	return arr[pos];
}

template <typename T, size_t N>
inline typename array<T, N>::reference array<T, N>::front()
{
	return arr[0];
}

template <typename T, size_t N>
inline typename array<T, N>::const_reference array<T, N>::front() const
{
	return arr[0];
}

template <typename T, size_t N>
inline typename array<T, N>::reference array<T, N>::operator [](typename array<T, N>::size_type pos)
{
	return arr[pos];
}

template <typename T, size_t N>
inline typename array<T, N>::const_reference array<T, N>::operator [](typename array<T, N>::size_type pos) const
{
	return arr[pos];
}

template <typename T, size_t N>
inline bool operator ==	( const array<T, N>& l, const array<T, N>& r )
{
	return equal( l.begin(), l.end(), r.begin() );
}

template <typename T, size_t N>
inline bool operator !=	( const array<T, N>& l, const array<T, N>& r )
{
	return !(l == r);
}

#if 0
template <typename T, size_t N>
inline bool operator <	( const array<T, N>& l, const array<T, N>& r )
{
}

template <typename T, size_t N>
inline bool operator <=	( const array<T, N>& l, const array<T, N>& r )
{
}

template <typename T, size_t N>
inline bool operator <	( const array<T, N>& l, const array<T, N>& r )
{
}

template <typename T, size_t N>
inline bool operator >=	( const array<T, N>& l, const array<T, N>& r )
{
}

template <typename T, size_t N>
inline bool operator >	( const array<T, N>& l, const array<T, N>& r )
{
}
#endif

template <typename T, size_t N>
inline void swap ( const array<T, N>& l, const array<T, N>& r )
{
	l.swap( r );
}

template <int I, class T, size_t N>
inline T& get( array<T, N>& arr )
{
	return arr[I];
}

template <int I, class T, size_t N>
inline const T& get( const array<T, N>& arr )
{
	return arr[I];
}

#endif	// _MH_STL_ARRAY_INL_