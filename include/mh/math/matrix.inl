#pragma		once
#ifndef		_MH_MATH_MATRIX_INL_
#define		_MH_MATH_MATRIX_INL_

/*
 *	Matrix3x3
 */

inline
Matrix3x3::Matrix3x3()
{}

inline
Matrix3x3::Matrix3x3( f32 _00, f32 _01, f32 _02,
					 f32 _10, f32 _11, f32 _12,
					 f32 _20, f32 _21, f32 _22 )
#if 0
					 : m[0][0](_00), m[0][1](_01), m[0][2](_02)
					 , m[1][0](_10), m[1][1](_11), m[1][2](_12)
					 , m[2][0](_20), m[2][1](_21), m[2][2](_22)
#endif
{
	m[0][0] = _00;
	m[0][1] = _01;
	m[0][2] = _02;
	m[1][0] = _10;
	m[1][1] = _11;
	m[1][2] = _12;
	m[2][0] = _20;
	m[2][1] = _21;
	m[2][2] = _22;
}

inline bool
Matrix3x3::operator == ( const Matrix3x3& rhs ) const
{
	return (m[0][0] == rhs.m[0][0] && m[0][1] == rhs.m[0][1] && m[0][2] == rhs.m[0][2]
		&& m[1][0] == rhs.m[1][0] && m[1][1] == rhs.m[1][1] && m[1][2] == rhs.m[1][2]
		&& m[2][0] == rhs.m[2][0] && m[2][1] == rhs.m[2][1] && m[2][2] == rhs.m[2][2] );
}

inline Matrix3x3&
Matrix3x3::transpose()
{
	const Matrix3x3 temp( *this );
	m[0][1] = temp.m[1][0];
	m[0][2] = temp.m[2][0];
	m[1][0] = temp.m[0][1];
	m[1][2] = temp.m[2][1];
	m[2][0] = temp.m[0][2];
	m[2][1] = temp.m[1][2];
	return *this;
}

inline Matrix3x3&
Matrix3x3::multiply( const Matrix3x3& rhs )
{
	m[0][0] = (m[0][0] * rhs.m[0][0]) + (m[0][1] * rhs.m[1][0]) + (m[0][2] * rhs.m[2][0]);
	m[0][1] = (m[0][0] * rhs.m[0][1]) + (m[0][1] * rhs.m[1][1]) + (m[0][2] * rhs.m[2][1]);
	m[0][2] = (m[0][0] * rhs.m[0][2]) + (m[0][1] * rhs.m[1][2]) + (m[0][2] * rhs.m[2][2]);
	m[1][0] = (m[1][0] * rhs.m[0][0]) + (m[1][1] * rhs.m[1][0]) + (m[1][2] * rhs.m[2][0]);
	m[1][1] = (m[1][0] * rhs.m[0][1]) + (m[1][1] * rhs.m[1][1]) + (m[1][2] * rhs.m[2][1]);
	m[1][2] = (m[1][0] * rhs.m[0][2]) + (m[1][1] * rhs.m[1][2]) + (m[1][2] * rhs.m[2][2]);
	m[2][0] = (m[2][0] * rhs.m[0][0]) + (m[2][1] * rhs.m[1][0]) + (m[2][2] * rhs.m[2][0]);
	m[2][1] = (m[2][0] * rhs.m[0][1]) + (m[2][1] * rhs.m[1][1]) + (m[2][2] * rhs.m[2][1]);
	m[2][2] = (m[2][0] * rhs.m[0][2]) + (m[2][1] * rhs.m[1][2]) + (m[2][2] * rhs.m[2][2]);
	return *this;
}

inline bool
Matrix3x3::operator != ( const Matrix3x3& rhs ) const
{
	return !(*this == rhs);
}

inline Matrix3x3
Matrix3x3::operator + () const
{
	return *this;
}

inline Matrix3x3
Matrix3x3::operator - () const
{
	return Matrix3x3(
		-m[0][0], -m[0][1], -m[0][2],
		-m[1][0], -m[1][1], -m[1][2],
		-m[2][0], -m[2][1], -m[2][2]
	);
}

inline Matrix3x3&
Matrix3x3::operator += ( const Matrix3x3& rhs )
{
	m[0][0] += rhs.m[0][0];
	m[0][1] += rhs.m[0][1];
	m[0][2] += rhs.m[0][2];
	m[1][0] += rhs.m[1][0];
	m[1][1] += rhs.m[1][1];
	m[1][2] += rhs.m[1][2];
	m[2][0] += rhs.m[2][0];
	m[2][1] += rhs.m[2][1];
	m[2][2] += rhs.m[2][2];
	return *this;
}

inline Matrix3x3&
Matrix3x3::operator -= ( const Matrix3x3& rhs )
{
	Matrix3x3 temp( -rhs );
	*this += temp;
	return *this;
}

inline Matrix3x3&
Matrix3x3::operator *= ( const Matrix3x3& rhs )
{
	return multiply(rhs);
}

inline Matrix3x3&
Matrix3x3::operator *= ( f32 rhs )
{
	m[0][0] *= rhs;
	m[0][1] *= rhs;
	m[0][2] *= rhs;
	m[1][0] *= rhs;
	m[1][1] *= rhs;
	m[1][2] *= rhs;
	m[2][0] *= rhs;
	m[2][1] *= rhs;
	m[2][2] *= rhs;
	return *this;
}

inline Matrix3x3&
Matrix3x3::operator /= ( f32 rhs )
{
	assert( rhs != 0.0f );
	const f32 temp = 1.0f / rhs;
	*this *= temp;
	return *this;
}

inline Matrix3x3
Matrix3x3::operator + ( const Matrix3x3& rhs ) const
{
	Matrix3x3 ret( *this );
	ret += rhs;
	return ret;
}

inline Matrix3x3
Matrix3x3::operator - ( const Matrix3x3& rhs ) const
{
	Matrix3x3 ret( *this );
	ret -= rhs;
	return ret;
}

inline Matrix3x3
Matrix3x3::operator * ( const Matrix3x3& rhs ) const
{
	Matrix3x3 ret = *this;
	ret *= rhs;
	return ret;
}

inline Matrix3x3
Matrix3x3::operator * ( f32 rhs ) const
{
	Matrix3x3 ret( *this );
	ret *= rhs;
	return ret;
}

inline Matrix3x3
Matrix3x3::operator / ( f32 rhs ) const
{
	Matrix3x3 ret( *this );
	ret /= rhs;
	return ret;
}


/*
 *	Matrix4x4
 */
inline
Matrix4x4::Matrix4x4( f32 _00, f32 _01, f32 _02, f32 _03,
				f32 _10, f32 _11, f32 _12, f32 _13,
				f32 _20, f32 _21, f32 _22, f32 _23,
				f32 _30, f32 _31, f32 _32, f32 _33 )
#if 0
				: m[0][0](_00), m[0][1](_01), m[0][1](_02), m[0][3](_03)
				, m[1][0](_10), m[1][1](_11), m[1][1](_12), m[1][3](_13)
				, m[2][0](_20), m[2][1](_21), m[2][1](_22), m[2][3](_23)
				, m[3][0](_30), m[3][1](_31), m[3][1](_32), m[3][3](_33)
#endif
{
	m[0][0] = _00; m[0][1] = _01; m[0][2] = _02; m[0][3] = _03;
	m[1][0] = _10; m[1][1] = _11; m[1][2] = _12; m[1][3] = _13;
	m[2][0] = _20; m[2][1] = _21; m[2][2] = _22; m[2][3] = _23;
	m[3][0] = _30; m[3][1] = _31; m[3][2] = _32; m[3][3] = _33;
}


#if 0
/*
 *	Matrix
 */
inline
Matrix::Matrix()
{
	identity();
}

inline
Matrix::Matrix(	f32 m00, f32 m01, f32 m02, f32 m03,
			    f32 m10, f32 m11, f32 m12, f32 m13,
				f32 m20, f32 m21, f32 m22, f32 m23,
				f32 m30, f32 m31, f32 m32, f32 m33 )
:	Float4x4( m00, m01, m02, m03,
			  m10, m11, m12, m13,
			  m20, m21, m22, m23,
			  m30, m31, m32, m33 )
{}

inline
Matrix::Matrix( const f32* pa )
:	Float4x4( pa )
{}

inline Matrix&
Matrix::identity()
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx = ::XMMatrixIdentity();
	::XMStoreFloat4x4( this, mtx );
#elif	defined(USING_D3DX_MATH)
	::D3DXMatrixIdentity( this );
#else
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;
#endif
	return *this;
}

inline Matrix&
Matrix::transpose()
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx = ::XMLoadFloat4x4( this );
	mtx = ::XMMatrixTranspose( mtx );
	::XMStoreFloat4x4( this, mtx );
#elif	defined(USING_D3DX_MATH)
	::D3DXMatrixTranspose( this, this );
#else
	Matrix mtx = *this;
	m[0][1] = mtx.m[1][0];	m[0][2] = mtx.m[2][0];	m[0][3] = mtx.m[3][0];
	m[1][0] = mtx.m[0][1];	m[1][2] = mtx.m[2][1];	m[1][3] = mtx.m[3][1];
	m[2][0] = mtx.m[0][2];	m[2][1] = mtx.m[1][2];	m[2][3] = mtx.m[3][2];
	m[3][0] = mtx.m[0][3];	m[3][1] = mtx.m[1][3];	m[3][2] = mtx.m[2][3];
#endif
	return *this;
}

inline Matrix&
Matrix::invert()
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx = ::XMLoadFloat4x4( this );
	::XMVECTOR determinant;
	mtx = ::XMMatrixInverse( &determinant, mtx );
	MH_ASSERT( !::XMMatrixIsInfinite( mtx ) );
	::XMStoreFloat4x4( this, mtx );
#elif	defined(USING_D3DX_MATH)
	::D3DXMatrixInverse( this, NULL, this );
	MH_ASSERT( this != NULL );
#else
	MH_ASSERT( false );
#endif
	return *this;
}

inline Matrix&
Matrix::multiply( const Matrix& m )
{
	*this *= m;
	return *this;
}

inline Matrix&
Matrix::scale( f32 x, f32 y, f32 z )
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMMatrixScaling( x, y, z );
	mtx0 = ::XMMatrixMultiply( mtx0, mtx1 );
	::XMStoreFloat4x4( this, mtx0 );
#elif	defined(USING_D3DX_MATH)
	Matrix temp;
	::D3DXMatrixScaling( &temp, x, y, z );
	*this *= temp;
#else
	Matrix temp;
	temp.m[0][0] = x;
	temp.m[1][1] = y;
	temp.m[2][2] = z;
	*this *= temp;
#endif
	return *this;
}

inline Matrix&
Matrix::scale( f32 s )
{
	return scale( s, s, s );
}

inline Matrix&
Matrix::scale( const Vector& v )
{
	return scale( v.x, v.y, v.z );
}

inline Matrix&
Matrix::init_translation()
{
	return set_translation( 0.0f, 0.0f, 0.0f );
}

inline Matrix&
Matrix::translate( f32 x, f32 y, f32 z )
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMMatrixTranslation( x, y, z );
	mtx0 = ::XMMatrixMultiply( mtx0, mtx1 );
	::XMStoreFloat4x4( this, mtx0 );
#elif	defined(USING_D3DX_MATH)
	Matrix temp;
	::D3DXMatrixTranslation( &temp, x, y, z );
	*this *= temp;
#else
	Matrix temp;
	temp.m[3][0] = x;
	temp.m[3][1] = y;
	temp.m[3][2] = z;
	*this *= temp;
#endif
	return *this;
}

inline Matrix&
Matrix::translate( const Vector& v )
{
	return translate( v.x, v.y, v.z );
}

inline Matrix&
Matrix::set_translation( f32 x, f32 y, f32 z )
{
	m[3][0] = x;
	m[3][1] = y;
	m[3][2] = z;
	return *this;
}

inline Matrix&
Matrix::set_translation( const Vector& v )
{
	return set_translation( v.x, v.y, v.z );
}

inline Vector
Matrix::get_translation() const
{
	return Vector( m[3][0], m[3][1], m[3][2] );
}

#if 0
inline Matrix&
Matrix::init_rotation()
{
	m[0][0] = m[1][1] = m[2][2] = 1.0f;
	m[0][1] = m[0][2] = m[1][0] = m[1][2] = m[2][0] = m[2][1] = 0.0f;
	return *this;
}
#endif

inline Matrix&
Matrix::rotate( f32 pitch, f32 yaw, f32 roll )
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMMatrixRotationRollPitchYaw( roll, pitch, yaw );
	mtx0 = ::XMMatrixMultiply( mtx0, mtx1 );
	::XMStoreFloat4x4( this, mtx0 );
#elif	defined(USING_D3DX_MATH)
	Matrix temp;
	::D3DXMatrixRotationYawPitchRoll( &temp, yaw, pitch, roll );
	*this *= temp;
#else
	MH_ASSERT( false );
	Matrix temp;
	*this *= temp;
#endif
	return *this;
}

inline Matrix&
Matrix::rotate( const Vector& axis, f32 angle )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat3( &axis );
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMMatrixRotationAxis( v, angle );
	mtx0 = ::XMMatrixMultiply( mtx0, mtx1 );
	::XMStoreFloat4x4( this, mtx0 );
#elif	defined(USING_D3DX_MATH)
	Matrix temp;
	::D3DXMatrixRotationAxis( &temp, &axis, angle );
	*this *= temp;
#else
	MH_ASSERT( false );
#endif
	return *this;
}

inline Matrix&
Matrix::rotate( const Quaternion& q )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v = ::XMLoadFloat4( &q );
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMMatrixRotationQuaternion( v );
	mtx0 = ::XMMatrixMultiply( mtx0, mtx1 );
	::XMStoreFloat4x4( this, mtx0 );
#elif	defined(USING_D3DX_MATH)
	Matrix temp;
	::D3DXMatrixRotationQuaternion( &temp, (const D3DXQUATERNION*)&q );
	*this *= temp;
#else
	MH_ASSERT( false );
#endif
	return *this;
}

inline Matrix&
Matrix::rotate_x( f32 angle )
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMMatrixRotationX( angle );
	mtx0 = ::XMMatrixMultiply( mtx0, mtx1 );
	::XMStoreFloat4x4( this, mtx0 );
#elif	defined(USING_D3DX_MATH)
	Matrix temp;
	::D3DXMatrixRotationX( &temp, angle );
	*this *= temp;
#else
	MH_ASSERT( false );
#endif
	return *this;
}

inline Matrix&
Matrix::rotate_y( f32 angle )
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMMatrixRotationY( angle );
	mtx0 = ::XMMatrixMultiply( mtx0, mtx1 );
	::XMStoreFloat4x4( this, mtx0 );
#elif	defined(USING_D3DX_MATH)
	Matrix temp;
	::D3DXMatrixRotationY( &temp, angle );
	*this *= temp;
#else
	MH_ASSERT( false );
#endif
	return *this;
}

inline Matrix&
Matrix::rotate_z( f32 angle )
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMMatrixRotationZ( angle );
	mtx0 = ::XMMatrixMultiply( mtx0, mtx1 );
	::XMStoreFloat4x4( this, mtx0 );
#elif	defined(USING_D3DX_MATH)
	Matrix temp;
	::D3DXMatrixRotationZ( &temp, angle );
	*this *= temp;
#else
	MH_ASSERT( false );
#endif
	return *this;
}

inline bool
Matrix::is_identity() const
{
	bool result;
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx = ::XMLoadFloat4x4( this );
	result = ( ::XMMatrixIsIdentity( mtx ) == TRUE );
#elif	defined(USING_D3DX_MATH)
	result = ( ::D3DXMatrixIsIdentity( this ) == TRUE );
#else
	result = ( *this == IDENTITY );
#endif
	return result;
}

inline bool
Matrix::is_zero() const
{
	return ( *this == ZERO );
}

inline bool
Matrix::has_inverse() const
{
	bool result;
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx = ::XMLoadFloat4x4( this );
	::XMVECTOR determinant = ::XMMatrixDeterminant( mtx );
	result = ( ::XMVector4Equal( determinant, g_XMZero ) == TRUE );
#elif	defined(USING_D3DX_MATH)
	result = ( ::D3DXMatrixDeterminant( this ) != 0.0f );
#else
	MH_ASSERT( false );
#endif
	return result;
}

inline Vector
Matrix::transform_vector( const Vector& v ) const
{
	Vector temp;
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx = ::XMLoadFloat4x4( this );
	::XMVECTOR v0 = ::XMLoadFloat3( &v );
	v0 = ::XMVector3TransformCoord( v0, mtx );
	::XMStoreFloat3( &temp, v0 );
#elif	defined(USING_D3DX_MATH)
	::D3DXVec3TransformCoord( &temp, &v, this );
#else
	MH_ASSERT( false );
#endif
	return temp;
}

inline Vector
Matrix::transform_normal( const Vector& n ) const
{
	Vector result;
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx = ::XMLoadFloat4x4( this );
	::XMVECTOR v = ::XMLoadFloat3( &n );
	v = ::XMVector3TransformNormal( v, mtx );
	::XMStoreFloat3( &result, v );
#elif	defined(USING_D3DX_MATH)
	// 法線変換には逆行列の転置行列を使う
	Matrix mat( *this );
	mat.invert().transpose();	
	::D3DXVec3TransformNormal( &result, &n, &mat );
#else
	MH_ASSERT( false );
#endif
	return result;
}

inline Matrix
Matrix::reflect( const Plane& p )
{
	Matrix temp;
#if		defined(USING_XNA_MATH)
	::XMVECTOR plane = ::XMLoadFloat4( &p );
	::XMMATRIX mtx = ::XMMatrixReflect( plane );
	::XMStoreFloat4x4( &temp, mtx );
#elif	defined(USING_D3DX_MATH)
	::D3DXMatrixReflect( &temp, (const D3DXPLANE*)&p );
#else
	MH_ASSERT( false );
#endif
	return temp;
}

inline Matrix
Matrix::inverse( const Matrix& _m )
{
	Matrix temp = _m;
	temp.invert();
	return temp;
}

inline Matrix
Matrix::transpose( const Matrix& _m )
{
	Matrix temp = _m;
	temp.transpose();
	return temp;
}

inline Matrix
Matrix::transform( const Vector& s, const Quaternion& r, const Vector& t )
{
	Matrix temp;
#if		defined(USING_XNA_MATH)
	::XMVECTOR _s = ::XMLoadFloat3( &s );
	::XMVECTOR _r = ::XMLoadFloat4( &r );
	::XMVECTOR _t = ::XMLoadFloat3( &t );
	::XMMATRIX _m = ::XMMatrixAffineTransformation( _s, (::XMVECTOR)g_XMZero, _r, _t );
	::XMStoreFloat4x4( &temp, _m );
#else
	Matrix scaling, rotation, translation;
	scaling.scale( s );
	rotation.rotate( r );
	translation.translate( t );
	temp = scaling * rotation * translation;
#endif
	return temp;
}

inline Matrix
Matrix::look_at( const Vector3& eye, const Vector3& target, const Vector3& up )
{
	::XMVECTOR e = ::XMLoadFloat3( &eye );
	::XMVECTOR t = ::XMLoadFloat3( &target );
	::XMVECTOR u = ::XMLoadFloat3( &up );
	::XMMATRIX m = ::XMMatrixLookAtLH( e, t, u );
	Matrix result;
	::XMStoreFloat4x4( &result, m );
	return result;
}

inline Matrix
Matrix::orthographic( f32 width, f32 height, f32 znear, f32 zfar )
{
	::XMMATRIX m = ::XMMatrixOrthographicLH( width, height, znear, zfar );
	Matrix result;
	::XMStoreFloat4x4( &result, m );
	return result;
}

inline Matrix
Matrix::perspective_fov( f32 yfov, f32 aspect, f32 znear, f32 zfar )
{
	::XMMATRIX m = ::XMMatrixPerspectiveLH( yfov, aspect, znear, zfar );
	Matrix result;
	::XMStoreFloat4x4( &result, m );
	return result;
}

inline Matrix
Matrix::operator + () const
{
	return *this;
}

inline Matrix
Matrix::operator - () const
{
#if	defined(USING_XNA_MATH)
	Matrix ret;
	::XMMATRIX mtx = ::XMLoadFloat4x4( this );
	mtx.r[0] = ::XMVectorNegate( mtx.r[0] );
	mtx.r[1] = ::XMVectorNegate( mtx.r[1] );
	mtx.r[2] = ::XMVectorNegate( mtx.r[2] );
	mtx.r[3] = ::XMVectorNegate( mtx.r[3] );
	::XMStoreFloat4x4( &ret, mtx );
	return ret;
#else
	return Matrix( -m[0][0], -m[0][1], -m[0][2], -m[0][3],
				   -m[1][0], -m[1][1], -m[1][2], -m[1][3],
				   -m[2][0], -m[2][1], -m[2][2], -m[2][3],
				   -m[3][0], -m[3][1], -m[3][2], -m[3][3] );
#endif
}

inline bool
Matrix::operator == ( const Matrix& rhs ) const
{
	bool result;
#if	defined(USING_XNA_MATH)
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMLoadFloat4x4( &rhs );
	result = ( ::XMVector4Equal( mtx0.r[0], mtx1.r[0] )
		&& ::XMVector4Equal( mtx0.r[1], mtx1.r[1] )
		&& ::XMVector4Equal( mtx0.r[2], mtx1.r[2] )
		&& ::XMVector4Equal( mtx0.r[3], mtx1.r[3] ) );	
#else
	result = ( _11 == rhs._11 && _12 == rhs._12 && _13 == rhs._13 && _14 == rhs._14
		&& _21 == rhs._21 && _22 == rhs._22 && _23 == rhs._23 && _24 == rhs._24
		&& _31 == rhs._31 && _32 == rhs._32 && _33 == rhs._33 && _34 == rhs._34
		&& _41 == rhs._41 && _42 == rhs._42 && _43 == rhs._43 && _44 == rhs._44 );
#endif
	return result;
}

inline bool
Matrix::operator != ( const Matrix& rhs ) const
{
	return !( *this == rhs );
}

inline f32
Matrix::operator () ( size_t row, size_t column ) const
{
	return m[row][column];
}

inline f32&
Matrix::operator () ( size_t row, size_t column )
{
	return m[row][column];
}

inline Matrix&
Matrix::operator += ( const Matrix& _m )
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMLoadFloat4x4( &_m );
	mtx0.r[0] = ::XMVectorAdd( mtx0.r[0], mtx1.r[0] );
	mtx0.r[1] = ::XMVectorAdd( mtx0.r[1], mtx1.r[0] );
	mtx0.r[2] = ::XMVectorAdd( mtx0.r[2], mtx1.r[0] );
	mtx0.r[3] = ::XMVectorAdd( mtx0.r[3], mtx1.r[0] );
	::XMStoreFloat4x4( this, mtx0 );
#else
	m[0][0] += _m.m[0][0];	m[0][1] += _m.m[0][1];	m[0][2] += _m.m[0][2];	m[0][3] += _m.m[0][3];
	m[1][0] += _m.m[1][0];	m[1][1] += _m.m[1][1];	m[1][2] += _m.m[1][2];	m[1][3] += _m.m[1][3];
	m[2][0] += _m.m[2][0];	m[2][1] += _m.m[2][1];	m[2][2] += _m.m[2][2];	m[2][3] += _m.m[2][3];
	m[3][0] += _m.m[3][0];	m[3][1] += _m.m[3][1];	m[3][2] += _m.m[3][2];	m[3][3] += _m.m[3][3];
#endif
	return *this;
}

inline Matrix&
Matrix::operator -= ( const Matrix& _m )
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMLoadFloat4x4( &_m );
	mtx0.r[0] = ::XMVectorSubtract( mtx0.r[0], mtx1.r[0] );
	mtx0.r[1] = ::XMVectorSubtract( mtx0.r[1], mtx1.r[0] );
	mtx0.r[2] = ::XMVectorSubtract( mtx0.r[2], mtx1.r[0] );
	mtx0.r[3] = ::XMVectorSubtract( mtx0.r[3], mtx1.r[0] );
	::XMStoreFloat4x4( this, mtx0 );
#else
	m[0][0] -= _m.m[0][0];	m[0][1] -= _m.m[0][1];	m[0][2] -= _m.m[0][2];	m[0][3] -= _m.m[0][3];
	m[1][0] -= _m.m[1][0];	m[1][1] -= _m.m[1][1];	m[1][2] -= _m.m[1][2];	m[1][3] -= _m.m[1][3];
	m[2][0] -= _m.m[2][0];	m[2][1] -= _m.m[2][1];	m[2][2] -= _m.m[2][2];	m[2][3] -= _m.m[2][3];
	m[3][0] -= _m.m[3][0];	m[3][1] -= _m.m[3][1];	m[3][2] -= _m.m[3][2];	m[3][3] -= _m.m[3][3];
#endif
	return *this;
}

inline Matrix&
Matrix::operator *= ( const Matrix& _m )
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx0 = ::XMLoadFloat4x4( this );
	::XMMATRIX mtx1 = ::XMLoadFloat4x4( &_m );
	mtx0 = ::XMMatrixMultiply( mtx0, mtx1 );
	::XMStoreFloat4x4( this, mtx0 );
#elif	defined(USING_D3DX_MATH)
	::D3DXMatrixMultiply( this, this, &_m );
#else
	MH_ASSERT( false );
#endif
	return *this;
}

inline Matrix&
Matrix::operator *= ( f32 s )
{
#if		defined(USING_XNA_MATH)
	::XMMATRIX mtx = ::XMLoadFloat4x4( this );
	mtx.r[0] = ::XMVectorScale( mtx.r[0], s );
	mtx.r[1] = ::XMVectorScale( mtx.r[1], s );
	mtx.r[2] = ::XMVectorScale( mtx.r[2], s );
	mtx.r[3] = ::XMVectorScale( mtx.r[3], s );
	::XMStoreFloat4x4( this, mtx );
#else
	m[0][0] *= s;	m[0][1] *= s;	m[0][2] *= s;	m[0][3] *= s;
	m[1][0] *= s;	m[1][1] *= s;	m[1][2] *= s;	m[1][3] *= s;
	m[2][0] *= s;	m[2][1] *= s;	m[2][2] *= s;	m[2][3] *= s;
	m[3][0] *= s;	m[3][1] *= s;	m[3][2] *= s;	m[3][3] *= s;
#endif
	return *this;
}

inline Matrix&
Matrix::operator /= ( f32 s )
{
#ifdef	_DEBUG_
	MH_ASSERT( s != 0.0f || s != -0.0f );
#endif
	const f32 invert = 1.0f / s;
	*this *= invert;
	return *this;
}

inline Matrix
Matrix::operator + ( const Matrix& _m ) const
{
	Matrix temp( *this );
	temp += _m;
	return temp;
}

inline Matrix
Matrix::operator - ( const Matrix& _m ) const
{
	Matrix temp( *this );
	temp -= _m;
	return temp;
}

inline Matrix
Matrix::operator * ( const Matrix& _m ) const
{
	Matrix temp( *this );
	temp *= _m;
	return temp;
}

inline Matrix
operator * ( f32 s, const Matrix& _m )
{
	Matrix temp( _m );
	temp *= s;
	return temp;
}

inline Matrix
Matrix::operator / ( f32 s ) const
{
	Matrix temp( *this );
	temp /= s;
	return temp;
}
#endif

#endif		/* _MH_MATH_MATRIX_INL_ */