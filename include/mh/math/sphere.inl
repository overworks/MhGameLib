#pragma		once
#ifndef		_MH_MATH_SPHERE_INL_
#define		_MH_MATH_SPHERE_INL_

/*
 *	Sphere
 */
inline Sphere::Sphere()
:	Float4( 0.0f, 0.0f, 0.0f, 0.0f )
{}

inline Sphere::Sphere( const Vector3& p, f32 r )
{
	set( p.x, p.y, p.z, r );
}

inline Sphere::Sphere( f32 _x, f32 _y, f32 _z, f32 r )
{
	set( _x, _y, _z, r );
}

inline Sphere&
Sphere::set( const Vector3& p, f32 r )
{
	return set( p.x, p.y, p.z, r );
}

inline Sphere&
Sphere::set( f32 _x, f32 _y, f32 _z, f32 r )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMVectorSet( _x, _y, _z, r );
	::XMStoreFloat4( this, v );
#else
	x = _x;
	y = _y;
	z = _z;
	w = r;
#endif
	return *this;
}

inline Sphere&
Sphere::set_position( const Vector3& p )
{
	return set_position( p.x, p.y, p.z );
}

inline Sphere&
Sphere::set_position( f32 _x, f32 _y, f32 _z )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMVectorSet( _x, _y, _z, 1.0f );
	::XMStoreFloat3( (::XMFLOAT3*)this, v );
#else
	x = _x;
	y = _y;
	z = _z;
#endif
	return *this;
}

inline Sphere&
Sphere::set_radius( f32 r )
{
	w = r;
	return *this;
}

inline bool
Sphere::operator == ( const Sphere& rhs ) const
{
	bool ret;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &rhs );
	ret = ( ::XMVector4Equal( v1, v2 ) == TRUE );
#else
	ret = ( x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w );
#endif
	return ret;
}

inline bool
Sphere::operator != ( const Sphere& rhs ) const
{
	bool ret;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &rhs );
	ret = ( ::XMVector4NotEqual( v1, v2 ) == TRUE );
#else
	ret = !( *this == rhs );
#endif
	return ret;
}

inline bool
Sphere::intersect( const Sphere& s1, const Sphere& s2 )
{
	bool ret;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( &s1 );
	::XMVECTOR v2 = ::XMLoadFloat4( &s2 );
	v1 = ::XMVectorSubtract( v1, v2 );
	v1 = ::XMVector3Length( v1 );
	ret = ( ::XMVectorGetX( v1 ) >= s1.w + s2.w );
#else
	const f32 length_sq = ( s1.x * s2.x ) + ( s1.y * s2.y ) + ( s1.z * s2.z );
	const f32 added_radius = s1.w + s2.w;
	ret = ( length_sq <= added_radius * added_radius );
#endif
	return ret;
}

#endif		/* _MH_MATH_SPHERE_INL_ */