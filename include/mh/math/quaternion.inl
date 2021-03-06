#pragma		once
#ifndef		_MH_MATH_QUATERNION_INL_
#define		_MH_MATH_QUATERNION_INL_

/*
 *	Quaternion
 */
inline
Quaternion::Quaternion()
{}

inline
Quaternion::Quaternion( f32 x, f32 y, f32 z, f32 w )
:	Float4( x, y, z, w )
{}

inline
Quaternion::Quaternion( const Vector3& axis, f32 angle )
{
	set( axis, angle );
}

inline
Quaternion::Quaternion( f32 pitch, f32 yaw, f32 roll )
{
	set( pitch, yaw, roll );
}

inline
Quaternion::Quaternion( const Matrix& matrix )
{
	set( matrix );
}

inline
Quaternion::Quaternion( const Vector3& origin, const Vector3& destination )
{
	set( origin, destination );
}

#if 0
inline
Quaternion::Quaternion( const f32* pArray )
:	Float4( pArray )
{}
#endif

inline f32
Quaternion::length() const
{
	f32 result;
#if		defined(USING_XNA_MATH)
	XMVECTOR v = ::XMLoadFloat4( this );
	v = ::XMQuaternionLength( v );
	result = ::XMVectorGetX( v );
#elif	defined(USING_D3DX_MATH)
	result = ::D3DXQuaternionLength( (const D3DXQUATERNION*)this );
#else
	result = sqrt( length_sq() );
#endif
	return result;
}

inline f32
Quaternion::length_sq() const
{
	f32 result;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( this );
	v = ::XMQuaternionLengthSq( v );
	result = ::XMVectorGetX( v );
#elif	defined(USING_D3DX_MATH)
	result = ::D3DXQuaternionLengthSq( (const D3DXQUATERNION*)this );
#else
	result = ( x * x ) + ( y * y ) + ( z * z ) + ( w * w );
#endif
	return result;
}

#if 0
inline Quaternion&
Quaternion::identity()
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMQuaternionIdentity();
	::XMStoreFloat4( this, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionIdentity( (D3DXQUATERNION*)this );
#else
	*this = IDENTITY;
#endif
	return *this;
}
#endif

inline Quaternion&
Quaternion::normalize()
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( this );
	v = ::XMQuaternionNormalize( v );
	::XMStoreFloat4( this, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionNormalize( (D3DXQUATERNION*)this, (const D3DXQUATERNION*)this );
#else
	const f32 len = length();
#ifdef	_DEBUG_
	MH_ASSERT( len != 0.0f && len != -0.0f );
#endif
	const f32 inv = 1.0f / len;
	*this *= inv;
#endif
	return *this;
}

inline Quaternion&
Quaternion::invert()
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( this );
	::XMQuaternionInverse( v );
	::XMStoreFloat4( this, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionInverse( (D3DXQUATERNION*)this, (const D3DXQUATERNION*)this );
#else
	const f32 len_sq = length_sq();
#ifdef	_DEBUG_
	MH_ASSERT( len_sq != 0.0f && len_sq != -0.0f );
#endif
	const f32 inv = 1.0f / len_sq;
	*this *= inv;
#endif
	return *this;
}

#if 0
inline Quaternion&
Quaternion::conjugate()
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( this );
	v = ::XMQuaternionConjugate( v );
	::XMStoreFloat4( this, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionConjugate( (D3DXQUATERNION*)this, (const D3DXQUATERNION*)this );
#else
	x = -x;
	y = -y;
	z = -z;
#endif
	return *this;
}
#endif

inline Quaternion&
Quaternion::set( f32 _x, f32 _y, f32 _z, f32 _w )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMVectorSet( _x, _y, _z, _w );
	::XMStoreFloat4( this, v );
#else
	x = _x;
	y = _y;
	z = _z;
	w = _w;
#endif
	return *this;
}

#if 0
inline Quaternion&
Quaternion::set( const f32* pa )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( (const ::XMFLOAT4*)pa );
	::XMStoreFloat4( this, v );
#else
#ifdef	_DEBUG_
	MH_ASSERT( pa != NULL );
#endif
	x = pa[0];
	y = pa[1];
	z = pa[2];
	w = pa[3];
#endif
	return *this;
}
#endif

inline Quaternion&
Quaternion::set( f32 pitch, f32 yaw, f32 roll )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMQuaternionRotationRollPitchYaw( pitch, yaw, roll );
	::XMStoreFloat4( this, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionRotationYawPitchRoll( (::D3DXQUATERNION*)this, yaw, pitch, roll );
#else
	*this = IDENTITY;
	rotate( Vector::X_AXIS, pitch );
	rotate( Vector::Y_AXIS, yaw );
	rotate( Vector::Z_AXIS, roll );
#endif
	return *this;
}

inline Quaternion&
Quaternion::set( const Vector& axis, f32 angle )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMQuaternionRotationAxis( ::XMLoadFloat3( &axis ), angle );
	::XMStoreFloat4( this, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionRotationAxis( (::D3DXQUATERNION*)this, &axis, angle );
#else
	MH_ASSERT( axis.is_unit() );
	const f32 half = angle * 0.5f;
	const f32 half_sin = sin( half );
	x = axis.x * half_sin;
	y = axis.y * half_sin;
	z = axis.z * half_sin;
	w = cos( half );	
#endif
	return *this;
}

inline Quaternion&
Quaternion::set( const Vector& origin, const Vector& destination )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v0 = ::XMVector3Normalize( ::XMLoadFloat3( &origin ) );
	::XMVECTOR v1 = ::XMVector3Normalize( ::XMLoadFloat3( &destination ) );
	::XMVECTOR c = ::XMVector3Cross( v0, v1 );
	::XMVECTOR d = ::XMVector3Dot( v0, v1 );
	::XMVECTOR s = ::XMVectorSqrt( ::XMVectorScale( (::XMVectorAdd( ::XMVectorReplicate( 1.0f ), d ) ), 2 ) );
	v0 = ::XMVectorMultiply( c, ::XMVectorReciprocal( s ) );
	v1 = ::XMVectorScale( s, 0.5f );
	v0 = ::XMVectorSelect( v0, v1, ::XMVectorSelectControl( 0, 0, 0, 1 ) );
	::XMStoreFloat4( this, v0 );
#else
	Vector v1 = Vector::normalize( origin );
	Vector v2 = Vector::normalize( destination );
	MH_ASSERT( v1 != v2 && v1 != -v2 );
	Vector c = Vector::cross( v1, v2 );
	f32 d = Vector::dot( v1, v2 );
	f32 s = sqrt( 2 * (1+d) );
	x = c.x / s;
	y = c.y / s;
	z = c.z / s;
	w = s / 2.0f;
#endif
	return *this;
}

inline Quaternion&
Quaternion::rotate( const Quaternion& q )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &q );
	v1 = ::XMQuaternionMultiply( v1, v2 );
	::XMStoreFloat4( this, v1 );	
#else
	*this *= q;
#endif	
	return *this;
}

inline Quaternion&
Quaternion::rotate( f32 pitch, f32 yaw, f32 roll )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMQuaternionRotationRollPitchYaw( roll, pitch, yaw );
	v1 = ::XMQuaternionMultiply( v1, v2 );
	::XMStoreFloat4( this, v1 );
#else
	Quaternion q( pitch, yaw, roll );
	*this *= q;
#endif
	return *this;
}

inline Quaternion&
Quaternion::rotate( const Vector& axis, f32 angle )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMQuaternionRotationAxis( XMLoadFloat3( &axis ), angle );
	v1 = ::XMQuaternionMultiply( v1, v2 );
	::XMStoreFloat4( this, v1 );
#else
	const Quaternion q( axis, angle );
	*this *= q;
#endif
	return *this;
}

inline void
Quaternion::to_axis_angle( Vector& axis, f32& angle ) const
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR q = ::XMLoadFloat4( this );
	::XMVECTOR a;
	::XMQuaternionToAxisAngle( &a, &angle, q );
	::XMStoreFloat3( &axis, a );
	MH_ASSERT( w > -1 && w < 1 );
	angle = 2 * acos( w );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionToAxisAngle( (D3DXQUATERNION*)this, &axis, &angle );
#else
	angle = acos(w) * 2;
	const f32 v = sqrt( 1 - (w * w) );
	const f32 v_inv = 1.0f / v;
	axis.x = x * v_inv;
	axis.y = y * v_inv;
	axis.z = z * v_inv;
#endif
}

inline void
Quaternion::to_matrix( Matrix& matrix ) const
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( this );
	::XMMATRIX m = ::XMMatrixRotationQuaternion( v );
	::XMStoreFloat4x4( &matrix, m );
#elif	defined(USING_D3DX_MATH)
	::D3DXMatrixRotationQuaternion( &matrix, (const D3DXQUATERNION*)this );
#else
	f32 s, xs, ys, zs, wx, wy, wz, xx, xy, xz, yy, yz, zz;

	s = 2.0f / (x*x + y*y + z*z + w*w);

	xs = s * x;		ys = s * y;		zs = s * z;
	wx = w * xs;	wy = w * ys;	wz = w * zs;
	xx = x * xs;	xy = x * ys;	xz = x * zs;
	yy = y * ys;	yz = y * zs;	zz = z * zs;

	matrix.m[0][3] = 0.0f;
	matrix.m[1][3] = 0.0f;
	matrix.m[2][3] = 0.0f;

	matrix.m[3][0] = 0.0f;
	matrix.m[3][1] = 0.0f;
	matrix.m[3][2] = 0.0f;
	matrix.m[3][3] = 1.0f;
	
#endif
}

inline bool
Quaternion::is_unit() const
{
	return ( length_sq() == 1.0f );
}

inline Quaternion
Quaternion::exp( const Quaternion& q )
{
	Quaternion ret;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( &q );
	v = ::XMQuaternionExp( v );
	::XMStoreFloat4( &ret, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionExp( &ret, &q );
#else
	MH_ASSERT( false );
	q;
#endif
	return ret;
}

inline Quaternion
Quaternion::exp() const
{
	return Quaternion( Quaternion::exp( *this ) );
}

inline Quaternion
Quaternion::ln( const Quaternion& q )
{
	Quaternion ret;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( &q );
	v = ::XMQuaternionLn( v );
	::XMStoreFloat4( &ret, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionLn( &ret, &q );
#else
	MH_ASSERT( false );
	q;
#endif
	return ret;
}

inline Quaternion
Quaternion::ln() const
{
	return Quaternion( Quaternion::ln( *this ) );
}

inline Vector3
Quaternion::rotate_vector( const Vector3& v ) const
{
	MH_ASSERT( this->is_unit() );
	Vector3 result;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat3( &v );
	::XMVECTOR v2 = ::XMLoadFloat4( this );
	v1 = ::XMVector3Rotate( v1, v2 );
	::XMStoreFloat3( &result, v1 );
#else
	f32 vmult = 2.0f * ( x * v.x + y * v.y + z * v.z );
	f32 crossmult = 2.0f * w;
	f32 pmult = crossmult * w - 1.0f;
	result.x = pmult * v.x + vmult * x + crossmult * ( y * v.z - z * v.y );
	result.y = pmult * v.y + vmult * y + crossmult * ( z * v.x - x * v.z );
	result.z = pmult * v.z + vmult * z + crossmult * ( x * v.y - y * v.x );
#endif
	return result;
}

#if 0
inline Quaternion
Quaternion::squad( const Quaternion& q1, const Quaternion& q2, const Quaternion& q3, const Quaternion& q4, f32 t )
{
	Quaternion result;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v0, v1, v2, v3;
	
#endif
	return result;
}

inline Quaternion::operator f32*()
{
	return (f32*)&x;
}

inline Quaternion::operator const f32* () const
{
	return (f32*)&x;
}
#endif

inline Quaternion&
Quaternion::operator += ( const Quaternion& q )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &q );
	v1 = ::XMVectorAdd( v1, v2 );
	::XMStoreFloat4( this, v1 );
#elif	defined(USING_D3DX_MATH)
	::D3DXVec4Add( this, this, &q );
#else
	x += q.x;
	y += q.y;
	z += q.z;
	w += q.w;
#endif
	return *this;
}

inline Quaternion&
Quaternion::operator -= ( const Quaternion& q )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &q );
	v1 = ::XMVectorSubtract( v1, v2 );
	::XMStoreFloat4( this, v1 );
#elif	defined(USING_D3DX_MATH)
	::D3DXVec4Subtract( this, this, &q );
#else
	x -= q.x;
	y -= q.y;
	z -= q.z;
	w -= q.w;
#endif
	return *this;
}

inline Quaternion&
Quaternion::operator *= ( const Quaternion& q )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &q );	
	v1 = ::XMQuaternionMultiply( v1, v2 );
	::XMStoreFloat4( this, v1 );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionMultiply( (D3DXQUATERNION*)this, (const D3DXQUATERNION*)this, (const D3DXQUATERNION*)&q );
#else
	Vector3 v1( x, y, z );
	Vector3 v2( q.x, q.y, q.z );
	Vector3 v3 = v1 * q.w + v2 * w + Vector::cross( v2, v1 );
	x = v3.x;
	y = v3.y;
	z = v3.z;
	w = w * q.w - Vector::dot( v1, v2 );
#endif
	return *this;
}

inline Quaternion&
Quaternion::operator *= ( f32 s )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( this );
	v = ::XMVectorScale( v, s );
	::XMStoreFloat4( this, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXVec4Scale( this, this, s );
#else
	x *= s;
	y *= s;
	z *= s;
	w *= s;
#endif
	return *this;
}

inline Quaternion&
Quaternion::operator /= ( f32 s )
{
#ifdef	_DEBUG_
	MH_ASSERT( s != 0.0f && s != -0.0f );
#endif
	const f32 inv = 1.0f / s;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( this );
	v = ::XMVectorScale( v, inv );
	::XMStoreFloat4( this, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXVec4Scale( this, this, inv );
#else
	x *= inv;
	y *= inv;
	z *= inv;
	w *= inv;
#endif
	return *this;
}

inline Quaternion
Quaternion::normalize( const Quaternion& q )
{
	Quaternion result;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( &q );
	v = ::XMQuaternionNormalize( v );
	::XMStoreFloat4( &result, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionNormalize( (const ::D3DXQUATERNION*)&result, (const ::D3DXQUATERNION*)&q );
#else
	result = q;
	result.normalize();
#endif
	return result;
}

inline Quaternion
Quaternion::conjugate( const Quaternion& q )
{
	Quaternion result;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( &q );
	v = ::XMQuaternionConjugate( v );
	::XMStoreFloat4( &result, v );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionConjugate( (const ::D3DXQUATERNION*)&result, (const ::D3DXQUATERNION*)&q );
#else
	result.x = -q.x;
	result.y = -q.y;
	result.z = -q.z;
	result.w = q.w;
#endif
	return result;
}

inline Quaternion
Quaternion::invert( const Quaternion& q )
{
	Quaternion result = q;
	result.invert();
	return result;
}

inline Vector3
Quaternion::rotate_vector( const Quaternion& q, const Vector3& v )
{
	return Vector3( q.rotate_vector(v) );
}

inline f32
Quaternion::distance( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion q = q1 - q2;
	f32 distance = q.length();
	return distance;
}

inline Quaternion
Quaternion::slerp( const Quaternion& q1, const Quaternion& q2, f32 t )
{
	Quaternion result;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( &q1 );
	::XMVECTOR v2 = ::XMLoadFloat4( &q2 );
	v1 = ::XMQuaternionSlerp( v1, v2, t );
	::XMStoreFloat4( &result, v1 );
#elif	defined(USING_D3DX_MATH)
	::D3DXQuaternionSlerp( (::D3DXQUATERNION*)&result, (const ::D3DXQUATERNION*)&q1, (const ::D3DXQUATERNION*)&q2, t );
#else
	MH_ASSERT( false );
	q1;
	q2;
	t = t;
#endif
	return result;
}

inline Quaternion
Quaternion::operator + () const
{
	return *this;
}

inline Quaternion
Quaternion::operator - () const
{
	return Quaternion( -x, -y, -z, -w );
}

inline Quaternion
operator + ( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion result = q1;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( &q1 );
	::XMVECTOR v2 = ::XMLoadFloat4( &q2 );
	v1 = ::XMVectorAdd( v1, v2 );
	::XMStoreFloat4( &result, v1 );
#else
	result += q2;
#endif
	return result;
}

inline Quaternion
operator - ( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion result = q1;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( &q1 );
	::XMVECTOR v2 = ::XMLoadFloat4( &q2 );
	v1 = ::XMVectorSubtract( v1, v2 );
	::XMStoreFloat4( &result, v1 );
#else
	result -= q2;
#endif
	return result;
}

inline Quaternion
operator * ( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion result = q1;
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &q );
	v1 = ::XMQuaternionMultiply( v1, v2 );
	::XMStoreFloat4( &result, v1 );
#else
	result *= q2;
#endif
	return result;
}

inline Quaternion
operator * ( const Quaternion& q, f32 s )
{
	Quaternion ret = q;
	ret *= s;
	return ret;
}

inline Quaternion
operator * ( f32 s, const Quaternion& q )
{
	Quaternion ret = q;
	ret *= s;
	return ret;
}

inline Quaternion
operator / ( const Quaternion& q, f32 s )
{
	Quaternion ret = q;
	ret /= s;
	return ret;
}

inline bool
operator == ( const Quaternion& q1, const Quaternion& q2 )
{
#if		defined(USING_XM_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( &q1 );
	::XMVECTOR v2 = ::XMLoadFloat4( &q2 );	
	return ( ::XMVector4Equal( v1, v2 ) == TRUE );
#else
	return ( q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w );
#endif
}

inline bool
operator != ( const Quaternion& q1, const Quaternion& q2 )
{
	return !( q1 == q2 );
}

#endif		/* _MH_MATH_QUATERNION_INL_ */