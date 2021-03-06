#pragma		once
#ifndef		_MH_MATH_PLAIN_INL_
#define		_MH_MATH_PLAIN_INL_

/*
 *	Plane
 */
/*
inline Plane::Plane()
:	Float4( 0.0f, 0.0f, 0.0f, 0.0f )
{}

inline Plane::Plane( const f32* parray )
:	Float4( parray )
{}
*/
inline
Plane::Plane( f32 a, f32 b, f32 c, f32 d )
:	Float4( a, b, c, d )
{}

inline
Plane::Plane( const Vector3& point, const Vector3& normal )
{
	set( point, normal );
}

inline
Plane::Plane( const Vector3& point1, const Vector3& point2, const Vector3& point3 )
{
	set( point1, point2, point3 );
}

inline Plane&
Plane::set( f32 a, f32 b, f32 c, f32 d )
{
#if		defined(USING_XNA_MATH)
	::XMVector3 v = ::XMVector3Set( a, b, c, d );
	::XMStoreFloat4( this, v );
#else
	x = a;
	y = b;
	z = c;
	w = d;
#endif
	return *this;
}

/*
inline Plane&
Plane::set( const f32* parray )
{
#if		defined(USING_XNA_MATH)
	::XMVector3 v = ::XMLoadFloat4( reinterpret_cast<const ::XMFLOAT4*>( parray ) );
	::XMStoreFloat4( this, v );
#else
	memcpy( this, parray, sizeof(Plane) );
#endif
	return *this;
}
*/

inline Plane&
Plane::set( const Vector3& point, const Vector3& normal )
{
#if		defined(USING_XNA_MATH)
	::XMVector3 p = ::XMLoadFloat3( &point );
	::XMVector3 n = ::XMLoadFloat3( &normal );
	p = ::XMPlaneFromPointNormal( p, n );
	::XMStoreFloat4( this, p );
#elif	defined(USING_D3DX_MATH)
	::D3DXPlaneFromPointNormal( (D3DXPLANE*)this, &point, &normal );
#else
	MH_ASSERT( normal.is_unit() );
	x = normal.x;
	y = normal.y;
	z = normal.z;
	w = -Vector3::dot( point, normal );
#endif
	return *this;
}

inline Plane&
Plane::set( const Vector3& point1, const Vector3& point2, const Vector3& point3 )
{
#if		defined(USING_XNA_MATH)
	::XMVector3 p1 = ::XMLoadFloat3( &point1 );
	::XMVector3 p2 = ::XMLoadFloat3( &point2 );
	::XMVector3 p3 = ::XMLoadFloat3( &point3 );
	p1 = ::XMPlaneFromPoints( p1, p2, p3 );
	::XMStoreFloat4( this, p1 );
#elif	defined(USING_D3DX_MATH)
	::D3DXPlaneFromPoints( (D3DXPLANE*)this, &point1, &point2, &point3 );
#else
	const Vector3 u = point2 - point1;
	const Vector3 v = point3 - point1;
	Vector3 n = Vector3::cross( u, v );
	n.normalize();
	x = n.x;
	y = n.y;
	z = n.z;
	w = Vector3::dot( n, point1 );
#endif
	return *this;
}

inline Plane&
Plane::normalize()
{
#if			defined(USING_XNA_MAHT)
	::XMVector3 v = ::XMLoadFloat4( this );
	v = ::XMPlaneNormalize( v );
	::XMStoreFloat4( this, v );
#elif		defined(USING_D3DX_MATH)
	::D3DXPlaneNormalize( (::D3DXPLANE*)this, (const ::D3DXPLANE*)this );
#else
	f32 reciprocal_length = 1.0f / sqrt( x * x + y * y + z * z + w * w );
	x *= reciprocal_length;
	y *= reciprocal_length;
	z *= reciprocal_length;
	w *= reciprocal_length;
#endif
	return *this;
}

inline f32
Plane::dot( const Vector4& point ) const
{
	f32 ret;
#if		defined(USING_XNA_MATH)
	::XMVector3 p = ::XMLoadFloat4( this );
	::XMVector3 v = ::XMLoadFloat4( &point );
	p = ::XMPlaneDot( p, v );
	ret = ::XMVector3GetX( p );
#elif	defined(USING_D3DX_MATH)
	ret = ::D3DXPlaneDot( (const D3DXPLANE*)this, &point );
#else
	ret = x * point.x + y * point.y + z * point.z + w * point.w;
#endif
	return ret;
}

inline f32
Plane::dot_coord( const Vector3& point ) const
{
	f32 ret;
#if		defined(USING_XNA_MATH)
	::XMVector3 p = ::XMLoadFloat4( this );
	::XMVector3 v = ::XMLoadFloat3( &point );
	p = ::XMPlaneDotCoord( p, v );
	ret = ::XMVector3GetX( p );
#elif	defined(USING_D3DX_MATH)
	ret = ::D3DXPlaneDotCoord( (const D3DXPLANE*)this, &point );
#else
	ret = x * point.x + y * point.y + z * point.z + w;
#endif
	return ret;
}

/*
inline bool
Plane::intersect_line( const Vector3& point1, const Vector3& point2, Vector3* intersect ) const
{
	bool ret;
#if		defined(USING_XNA_MATH)
	::XMVector3 p = ::XMLoadFloat4( this );
	::XMVector3 v1 = ::XMLoadFloat3( &point1 );
	::XMVector3 v2 = ::XMLoadFloat3( &point2 );
	p = ::XMPlaneIntersectLine( p, v1, v2 );
	ret = ( ::XMPlaneIsNaN( p ) != TRUE );
	if ( ret && intersect != NULL  )
		::XMStoreFloat3( intersect, p );
#elif	defined(USING_D3DX_MATH)
	::D3DXPlaneIntersectLine( intersect, (const D3DXPLANE*)this, &point1, &point2 );
	ret = ( intersect != NULL );
#else
	MH_ASSERT( false );
#endif
	return ret;
}

inline bool
Plane::intersect_plane( const Plane& plane, Vector3* intersect1, Vector3* intersect2 ) const
{
	bool ret;
#if		defined(USING_XNA_MATH)
	::XMVector3 p1 = ::XMLoadFloat4( this );
	::XMVector3 p2 = ::XMLoadFloat4( &plane );
	::XMVector3 v1, v2;
	::XMPlaneIntersectPlane( &v1, &v2, p1, p2 );
	ret = ( ::XMPlaneIsNaN( v1 ) != TRUE );
	if ( ret )
	{
		if ( intersect1 != NULL )
			::XMStoreFloat3( intersect1, v1 );
		if ( intersect2 != NULL )
			::XMStoreFloat3( intersect2, v2 );
	}
#else
	MH_ASSERT( false );
#endif
	return ret;
}
*/

inline bool
Plane::operator == ( const Plane& rhs ) const
{
	bool ret;
#if		defined(USING_XNA_MATH)
	::XMVector3 p1 = ::XMLoadFloat4( this );
	::XMVector3 p2 = ::XMLoadFloat4( &rhs );
	ret = ( ::XMPlaneEqual( p1, p2 ) == TRUE );
#else
	ret = ( x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w );
#endif
	return ret;
}

inline bool
Plane::operator != ( const Plane& rhs ) const
{
	bool ret;
#if		defined(USING_XNA_MATH)
	::XMVector3 p1 = ::XMLoadFloat4( this );
	::XMVector3 p2 = ::XMLoadFloat4( &rhs );
	ret = ( ::XMPlaneNotEqual( p1, p2 ) == TRUE );
#else
	ret = !( *this == rhs );
#endif
	return ret;
}

inline f32
Plane::distance( const Plane& plane, const Vector3& point )
{
	return abs( plane.dot_coord( point ) );
}

#endif		/* _MH_MATH_PLAIN_INL_ */