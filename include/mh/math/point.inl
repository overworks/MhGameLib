#pragma		once
#ifndef		_MH_MATH_POINT_INL_
#define		_MH_MATH_POINT_INL_

template<typename T>
inline Point<T>::Point( T _x, T _y )
:	x(_x), y(_y)
{}

template<typename T>
inline Point<T>&
Point<T>::set( T _x, T _y )
{
	x = _x;
	y = _y;
}

template<typename T>
inline T
Point<T>::length( const Point<T>& p1, const Point<T>& p2 )
{
	return static_cast<T>( sqrt( length_sq( p1, p2 ) ) );
}

template<typename T>
inline T
Point<T>::length_sq( const Point<T>& p1, const Point<T>& p2 )
{
	const T width = p1.x - p2.x;
	const T height = p1.y - p2.y;
	return ( width * width ) + ( height * height );
}

template<typename T>
inline Point<T>
Point<T>::center( const Point<T>& p1, const Point<T>& p2 )
{
	return Point<T>(
		( p1.x + p2.x ) / 2,
		( p1.y + p2.y ) / 2 );
}

#endif		/* _MH_MATH_POINT_INL_ */