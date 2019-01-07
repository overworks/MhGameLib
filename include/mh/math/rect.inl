#pragma		once
#ifndef		_MH_MATH_RECT_INL_
#define		_MH_MATH_RECT_INL_

template<typename T>
inline Rect<T>::Rect()
{}

template<typename T>
inline Rect<T>::Rect( T left, T top, T right, T bottom )
:	upper_left( left, top )
,	lower_right( right, bottom )
{}

template<typename T>
inline Rect<T>::Rect( const Point<T>& _upper_left, const Point<T>& _lower_right )
:	upper_left( _upper_left )
,	lower_right( _lower_right )
{}

template<typename T>
inline Rect<T>&
Rect<T>::set( T left, T top, T right, T bottom )
{
	upper_left.set( left, top );
	lower_right.set( right, bottom );
	return *this;
}

template<typename T>
inline Rect<T>&
Rect<T>::set( const Point<T>& _upper_left, const Point<T>& _lower_right )
{
	upper_left = _upper_left;
	lower_right = _lower_right;
	return *this;
}

template<typename T>
inline Rect<T>&
Rect<T>::repair()
{
	if ( upper_left.x > lower_right.x )
		swap( upper_left.x, lower_right.x );
	if ( upper_left.y > lower_right.y )
		swap( upper_left.y, lower_right.y );
	return *this;
}

template<typename T>
inline T
Rect<T>::width() const
{
	return lower_right.x - upper_left.x;
}

template<typename T>
inline T
Rect<T>::height() const
{
	return lower_right.y - upper_left.y;
}

template<typename T>
inline Point<T>
Rect<T>::center() const
{
	return Point<T>::center( upper_left, lower_right );
}

template<typename T>
inline bool
Rect<T>::is_valid() const
{
	return ( upper_left.x <= lower_right.x && upper_left.y <= lower_right.y );
}

template<typename T>
inline bool
Rect<T>::is_point_inside( const Point<T>& point ) const
{
	Rect<T> temp = *this;
	temp.repair();
	return ( temp.upper_left.x <= point.x && point.x <= temp.lower_right.x
		&& temp.lower_right.x <= point.y && point.y <= temp.upper_right.y );
}

template<typename T>
inline bool
Rect<T>::is_rect_collided( const Rect<T>& rect ) const
{
	Rect<T> temp1 = *this;
	temp1.repair();
	Rect<T> temp2 = rect;
	temp2.repair();
	
	return !( temp1.upper_left.x > temp2.lower_right.x
		|| temp1.upper_left.y > temp2.lower_right.y
		|| temp1.lower_right.x < temp2.upper_left.x
		|| temp1.lower_right.y < temp2.upper_left.y );
}


#endif		/* _MH_MATH_RECT_INL_ */