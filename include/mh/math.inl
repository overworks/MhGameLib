/*
 *	Algo namespace
 */
namespace Algo
{

	template<typename TYPE>
	inline TYPE abs(const TYPE& n )
	{
		return (n < (TYPE)0 ? -n : n);
	}

	template<typename LTYPE, typename RTYPE>
	inline const LTYPE div(const LTYPE& l, const RTYPE& r)
	{
		MH_ASSERT(r);
		return l / r;
	}

	template <typename TYPE>
	inline const s32 nor( TYPE n )
	{
		return ((n > (TYPE)0) ? 1: ((n < (TYPE)0)? -1 : 0));
	}

#if 0
	template<typename LTYPE, typename RTYPE>
	inline const LTYPE min(const LTYPE& l, const RTYPE& r)
	{
		return (l < r ? l : r);
	}

	template<typename LTYPE, typename RTYPE>
	inline const LTYPE max(const LTYPE& l, const RTYPE& r)
	{
		return (l < r ? r : l);
	}
#endif

	template<typename TYPE>
	void swap(TYPE& lhs, TYPE& rhs)
	{
		TYPE temp = lhs;
		lhs = rhs;
		rhs = temp;
	}

	template<typename TYPE>
	inline void zero(TYPE& a )
	{
		memset( &a, 0, sizeof(TYPE) );
	}

	template<typename TYPE>
	inline void zero_array(TYPE* p, u32 size )
	{
		memset( p, 0, sizeof(TYPE) * size);
	}

	template<typename TYPE>
	inline void del(TYPE& lp)									
	{
		if( lp )
		{
			delete lp;
			lp = NULL;
		}
	}

	template<typename TYPE>
	inline void array_del(TYPE& lp)
	{
		if( lp )
		{
			delete[] lp;
			lp = NULL;
		}
	}

	template<typename TYPE>
	inline TYPE meter(const TYPE& n)
	{
		return n * static_cast<TYPE>(D_METER);
	}

	template<typename TYPE>
	inline TYPE centi(const TYPE& n)
	{
		return n * static_cast<TYPE>(D_CENTI);
	}

	template<typename TYPE>
	inline TYPE milli(const TYPE& n)
	{
		return n * static_cast<TYPE>(D_MILLI);
	}

	template<typename TYPE>
	inline TYPE inch(const TYPE& n)
	{
		return n * static_cast<TYPE>(D_INCH);
	}

	template<typename TYPE>
	inline TYPE feet(const TYPE& n)
	{
		return n * static_cast<TYPE>(D_FEET);
	}

	template<typename TYPE>
	inline TYPE percent(const TYPE &n)
	{
		return n / static_cast<TYPE>(100);
	}

	inline void check_float_min(f32 &n)
	{
		if (::fabs(n) < MH_EPSILON)
			n = 0.0f;
	}

	inline f32 deg2rad(f32 d)
	{
		return (D_PI / 180.0f * d);
	}

	inline f32 rad2deg(f32 r)
	{
		return (r / D_PI * 180.0f);
	}

	inline f32 round_radian_pi(f32 r)
	{
		while (r > D_PI)	r -= 2.0f * D_PI;
		while (r < -D_PI)	r += 2.0f * D_PI;
		return r;
	}

	inline f32 round_radian_pi2(f32 r)
	{
		while (r > 2.0f * D_PI)	r -= 2.0f * D_PI;
		while (r < 0.0f)		r += 2.0f * D_PI;
		return r;
	}

	inline f32 round_degree_pi(f32 r)
	{
		while (r > 180.0f)		r -= 360.0f;
		while (r < -180.0f)		r += 360.0f;
		return r;
	}

	inline f32 round_degree_pi2(f32 r)
	{
		while (r > 360.0f)		r -= 360.0f;
		while (r < 0.0f)		r += 360.0f;
		return r;
	}

	template <typename InputIter, typename ValueFunc, typename ValueType>
	inline ValueType average(InputIter first, InputIter last, ValueFunc func)
	{
		if (first == last)
			return 0;		
		ValueType total = 0;
		for (InputIter it = first; it != last; ++it)
			total += func(*it);
		return total / (last - first);
	}

	template <typename InputIter, typename ValueType>
	inline ValueType average(InputIter first, InputIter last)
	{
		if (first == last)
			return 0;
		ValueType total = 0;
		for (InputIter it = first; it != last; ++it)
			total += *it;
		return total / (last - first);
	};

	template <typename InputIter, typename ValueFunc, typename ValueType>
	inline ValueType maximum(InputIter first, InputIter last, ValueFunc func)
	{
		MH_ASSERT(fisst != last);
		ValueType value = func(*first);
		for (InputIter it = first + 1; it != last; ++it)
		{
			ValueType n = func(*it);
			if (n > value)
				value = n;
		}
		return value;
	}

	template <typename InputIter, typename ValueType>
	inline ValueType maximum(InputIter first, InputIter last)
	{
		MH_ASSERT(first != last);
		ValueType value = *first;
		for (InputIter it = first + 1; it != last; ++it)
		{
			ValueType n = *it;
			if (n > value)
				value = n;
		}
		return value;
	}

	template <typename InputIter, typename ValueFunc, typename ValueType>
	inline ValueType minimum(InputIter first, InputIter last, ValueFunc func)
	{
		MH_ASSERT(fisst != last);
		ValueType value = func(*first);
		for (InputIter it = first + 1; it != last; ++it)
		{
			ValueType n = func(*it);
			if (n < value)
				value = n;
		}
		return value;
	}

	template <typename InputIter, typename ValueType>
	inline ValueType minimum(InputIter first, InputIter last)
	{
		MH_ASSERT(first != last);
		ValueType value = *first;
		for (InputIter it = first + 1; it != last; ++it)
		{
			ValueType n = *it;
			if (n < value)
				value = n;
		}
		return value;
	}

	template <typename InputIter, typename ValueFunc, typename ValueType>
	inline void range(InputIter first, InputIter last, ValueFunc func,
					ValueType &min_value, ValueType &max_value)
	{
		MH_ASSERT(first != last);
		min_value = max_value = func(*first);
		for (InputIter it = first + 1; it != last; ++it)
		{
			ValueType n = func(*it);
			if (n > max_value)	max_value = n;
			if (n < min_value)	min_value = n;
		}
	}

	template <typename InputIter, typename ValueType>
	inline void range(InputIter first, InputIter last,
					  ValueType &min_value, ValueType &max_value)
	{
		ASSERT(first != last);
		min_value = max_value = *first;
		for (InputIter it = first + 1; it != last; ++it) {
			ValueType n = *it;
			if (n > max_value)	max_value = n;
			if (n < min_value)	min_value = n;
		}
	}
}
/*
 *	PointI
 */
inline
PointI::PointI()
{
	init();
}

inline
PointI::PointI( s32 _x, s32 _y )
{
	set( _x, _y );
}

inline
PointI::PointI( const PointI& po )
{
	set( po );
}

inline void
PointI::init()
{
	set( 0, 0 );
}

inline void
PointI::set( s32 _x, s32 _y )
{
	x = _x;
	y = _y;
}

inline void
PointI::set( const PointI& p )
{
	set( p.x, p.y );
}

inline void
PointI::operator = ( const PointI& p )
{
	set( p );
}

/*
 *	PointF
 */
inline
PointF::PointF()
{
	init();
}

inline
PointF::PointF( f32 _x, f32 _y )
{
	set( _x, _y );
}

inline
PointF::PointF( const PointF& po )
{
	set( po );
}

inline void
PointF::init()
{
	set( 0.0f, 0.0f );
}

inline void
PointF::set( f32 _x, f32 _y )
{
	x = _x;
	y = _y;
}

inline void
PointF::set( const PointF& po )
{
	set( po.x, po.y );
}

inline void
PointF::operator = ( const PointF& po )
{
	set( po );
}

/*
 *	Segment Template
 */
template<typename T>
inline Segment<T>::Segment()
{}

template<typename T>
inline Segment<T>::Segment( const T& p1, const T& p2 )
:	point1(p1), point2( p2 )
{}

template<typename T>
inline T Segment<T>::center() const
{
	return T::center( point1, point2 );
}

template<typename T>
inline float Segment<T>::length() const
{
	return T::length( point1, point2 );
}

template<typename T>
inline float Segment<T>::length_sq() const
{
	return T::length_sq( point1, point2 );
}

/*
 *	Frustum
 */
inline
Frustum::Frustum()
{}

inline bool
Frustum::operator == ( const Frustum& rhs ) const
{
	return ( this->near_plane	== rhs.near_plane
		&& this->far_plane		== rhs.far_plane
		&& this->left_plane		== rhs.left_plane
		&& this->right_plane	== rhs.right_plane
		&& this->top_plane		== rhs.top_plane
		&& this->bottom_plane	== rhs.bottom_plane );
}

inline bool
Frustum::operator != ( const Frustum& rhs ) const
{
	return !( *this == rhs );
}