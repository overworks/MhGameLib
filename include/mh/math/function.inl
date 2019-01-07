#pragma		once
#ifndef		_MH_MATH_FUNCTION_INL_
#define		_MH_MATH_FUNCTION_INL_


inline s32 abs	( s32 x )			{ return std::abs( x );		}
inline f32 abs	( f32 x )			{ return std::abs( x );		}
inline f64 abs	( f64 x )			{ return std::abs( x );		}
inline f32 sqrt	( f32 x )			{ return std::sqrt( x );	}
inline f64 sqrt	( f64 x )			{ return std::sqrt( x );	}
inline f64 sin	( f64 x )			{ return std::sin( x );		}
inline f32 sin	( f32 x )			{ return std::sin( x );		}
inline f64 cos	( f64 x )			{ return std::cos( x );		}
inline f32 cos	( f32 x )			{ return std::cos( x );		}
inline f32 asin	( f32 x )			{ return std::asin( x );	}
inline f64 asin	( f64 x )			{ return std::asin( x );	}
inline f32 acos	( f32 x )			{ return std::acos( x );	}
inline f64 acos	( f64 x )			{ return std::acos( x );	}
inline f32 atan	( f32 x )			{ return std::atan( x );	}
inline f64 atan	( f64 x )			{ return std::atan( x );	}
inline f32 atan2( f32 y, f32 x )	{ return std::atan2( y, x );}
inline f64 atan2( f64 y, f64 x )	{ return std::atan2( y, x );}

inline f32	absf		( f32 x )	{ Universal u; u.f = x; u.s &= 0x7fffffff; return u.f; }
inline bool	positive	( f32 x )	{ Universal u; u.f = x; return ( ( u.s & 0x7fffffff ) != 0 ); }

// distance
inline f32 distance( const Vector3& point, const Line3& line )
{
	const Vector3 w = point - line.origin;
	const f32 v_sq = Vector3::dot( line.direction, line.direction );
	const f32 w_sq = Vector3::dot( w, w );
	const f32 proj = Vector3::dot( w, line.direction );
	return w_sq - proj * proj / v_sq;
}

// intersect
inline bool intersect( const Sphere& s1, const Sphere& s2 )
{
	bool ret;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( &s1 );
	::XMVECTOR v2 = ::XMLoadFloat4( &s2 );
	v1 = ::XMVectorSubtract( v1, v2 );
	v1 = ::XMVector3Length( v1 );
	ret = ( ::XMVectorGetX( v1 ) >= s1.w + s2.w );
#else
	const f32 length_sq = ((s1.x - s2.x) * (s1.x - s2.x)) + ((s1.y - s2.y) * (s1.y - s2.y)) + ((s1.z - s2.z) * (s1.z - s2.z));
	const f32 added_radius = s1.w + s2.w;
	ret = ( length_sq <= added_radius * added_radius );
#endif
	return ret;
}

inline bool intersect( const Sphere& s, const Line3& l )
{
	Vector3 w( s.x - l.origin.x, s.y - l.origin.y, s.z - l.origin.z );
	f32 w_sq = Vector3::dot( w, w );
	f32 r_sq = s.w * s.w;
	f32 proj = Vector3::dot( w, l.direction );

	if( proj < 0.0f && w_sq > r_sq )
		return false;

	f32 l_sq = Vector3::dot( l.direction, l.direction );
	return ( l_sq * w_sq - proj * proj <= l_sq * r_sq );
}


#endif		/* _MH_MATH_FUNCTION_INL_ */