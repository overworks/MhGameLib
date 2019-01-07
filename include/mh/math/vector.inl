#pragma		once
#ifndef		_MH_MATH_VECTOR_INL_
#define		_MH_MATH_VECTOR_INL_

inline
Vector2::Vector2()
:	Float2( 0.0f, 0.0f )
{}

inline
Vector2::Vector2( f32 _x, f32 _y )
:	Float2( _x, _y )
{}

inline Vector2&
Vector2::set( f32 _x, f32 _y )
{
	x = _x;
	y = _y;
	return *this;
}

inline Vector2&
Vector2::normalize()
{
	*this /= length();
	return *this;
}

inline f32
Vector2::length() const
{
	return sqrt( length_sq() );
}

inline f32
Vector2::length_sq() const
{
	return dot(*this, *this);
}

inline bool
Vector2::is_unit() const
{
	return ( length_sq() == 1.0f );
}

inline Vector2
Vector2::operator + () const
{
	return (*this);
}

inline Vector2
Vector2::operator - () const
{
	return Vector2( -x, -y );
}

inline Vector2&
Vector2::operator += ( const Vector2& v ) 
{
	x += v.x;
	y += v.y;
	return *this;
}

inline Vector2&
Vector2::operator -= ( const Vector2& v )
{
	x -= v.x;
	y -= v.y;
	return *this;
}

inline Vector2&
Vector2::operator *= ( const Vector2& v )
{
	x *= v.x;
	y *= v.y;
	return *this;
}

inline Vector2&
Vector2::operator /= ( const Vector2& v )
{
	MH_ASSERT( v.x != 0.0f && v.y != 0.0f );
	x /= v.x;
	y /= v.y;
	return *this;
}

inline Vector2&
Vector2::operator *= ( f32 s )
{
	x *= s;
	y *= s;
	return *this;
}

inline Vector2&
Vector2::operator /= ( f32 s )
{
	MH_ASSERT( s != 0.0f );
	const f32 inv = 1.0f / s;
	x *= inv;
	y *= inv;
	return *this;
}

inline f32
Vector2::operator [] (int i) const
{
	MH_ASSERT(i == 0 || i == 1);
	return *((float*)this + i);
}

inline Vector2
operator + ( const Vector2& v1, const Vector2& v2 )
{
	Vector2 ret = v1;
	ret += v2;
	return ret;
}

inline Vector2
operator - ( const Vector2& v1, const Vector2& v2 )
{
	Vector2 ret = v1;
	ret -= v2;
	return ret;
}

inline Vector2
operator * ( const Vector2& v1, const Vector2& v2 )
{
	Vector2 ret = v1;
	ret *= v2;
	return ret;
}

inline Vector2
operator / ( const Vector2& v1, const Vector2& v2 )
{
	Vector2 ret = v1;
	ret /= v2;
	return ret;
}

inline Vector2
operator * ( const Vector2& v, f32 s )
{
	Vector2 ret = v;
	ret *= s;
	return ret;
}

inline Vector2
operator * ( f32 s, const Vector2& v )
{
	Vector2 ret = v;
	ret *= s;
	return ret;
}

inline Vector2
operator / ( const Vector2& v, f32 s )
{
	Vector2 ret = v;
	ret /= s;
	return ret;
}

inline bool
operator == ( const Vector2& v1, const Vector2& v2 )
{
	return ( v1.x == v2.x && v1.y == v2.y );
}

inline bool
operator != ( const Vector2& v1, const Vector2& v2 )
{
	return !( v1 == v2 );
}

inline f32
Vector2::length( const Vector2& v )
{
	return v.length();
}

inline f32
Vector2::length_sq( const Vector2& v )
{
	return v.length_sq();
}

inline Vector2
Vector2::normalize( const Vector2& v )
{
	Vector2 ret = v;
	ret.normalize();
	return ret;
}

inline f32
Vector2::distance( const Vector2& v1, const Vector2& v2 )
{
	return sqrt( distance_sq( v1, v2 ) );
}

inline f32
Vector2::distance_sq( const Vector2& v1, const Vector2& v2 )
{
	const Vector2 temp = v1 - v2;
	const f32 length_sq = temp.length_sq();
	return length_sq;
}

inline f32
Vector2::dot( const Vector2& v1, const Vector2& v2 )
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

inline f32
Vector2::cross(const Vector2& v1, const Vector2& v2)
{
	return (v1.x * v2.y) - (v1.y * v2.x);
}

inline Vector2
Vector2::lerp( const Vector2& v1, const Vector2& v2, f32 t )
{
	return Vector2( ( v1 * ( 1.0f - t ) ) + ( v2 * t ) );
}

inline
Vector3::Vector3()
:	Float3( 0.0f, 0.0f, 0.0f )
{}

inline
Vector3::Vector3( f32 x, f32 y, f32 z )
:	Float3 ( x, y, z )
{}
	
inline Vector3&
Vector3::operator += ( const Vector3& v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}


inline Vector3&
Vector3::operator -= ( const Vector3& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

inline Vector3&
Vector3::operator *= ( const Vector3& v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

inline Vector3&
Vector3::operator /= ( const Vector3& v )
{
	MH_ASSERT( v.x != 0.0f && v.y != 0.0f && v.z != 0.0f );
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

inline Vector3&
Vector3::operator *= ( f32 f )
{
	x *= f;
	y *= f;
	z *= f;
	return *this;
}

inline Vector3&
Vector3::operator /= ( f32 f )
{
	const float inv = 1.0f / f;
	x *= inv;
	y *= inv;
	z *= inv;
	return *this;
}

inline Vector3
Vector3::operator + () const
{
	return Vector3(*this);
}

inline Vector3
Vector3::operator - () const
{	
	return Vector3(-x, -y, -z);
}

inline f32
Vector3::operator [] (int i) const
{
	MH_ASSERT(0 <= i && i <= 2);
	return *((float*)this + i);
}

inline Vector3
operator + ( const Vector3& v1, const Vector3& v2 )
{
	Vector3 ret = v1;
	ret += v2;
	return ret;
}

inline Vector3
operator - ( const Vector3& v1, const Vector3& v2 )
{
	Vector3 ret = v1;
	ret -= v2;
	return ret;
}

inline Vector3
operator * ( const Vector3& v1, const Vector3& v2 )
{
	Vector3 ret = v1;
	ret *= v2;
	return ret;
}

inline Vector3
operator / ( const Vector3& v1, const Vector3& v2 )
{
	Vector3 ret = v1;
	ret /= v2;
	return ret;
}

inline Vector3
operator * ( const Vector3& v, f32 s )
{
	Vector3 ret = v;
	ret *= s;
	return ret;
}

inline Vector3
operator * ( f32 s, const Vector3& v )
{
	Vector3 ret = v;
	ret *= s;
	return ret;
}

inline Vector3
operator / ( const Vector3& v, f32 s )
{
	const float inv = 1.0f / s;
	Vector3 ret = v;
	ret *= inv;
	return ret;
}

inline bool
operator == ( const Vector3& v1, const Vector3& v2 )
{
	return ( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z );
}

inline bool
operator != ( const Vector3& v1, const Vector3& v2 )
{
	return !( v1 == v2 );
}

inline Vector3&
Vector3::set(f32 _x, f32 _y, f32 _z)
{
	x = _x;
	y = _y;
	z = _z;
	return (*this);
}

inline Vector3&
Vector3::normalize()
{
	float m = magnitude();
	if (m != 0.0f)
	{
		*this /= m;
	}
	return *this;
}

inline f32
Vector3::magnitude() const
{
	return length();
}

inline f32
Vector3::length() const
{
	return sqrt(length_sq());
}

inline f32
Vector3::length_sq() const
{
	return dot(*this, *this);
}

inline bool
Vector3::is_unit() const
{
	return length_sq() == 1.0f;
}

inline f32
Vector3::length(const Vector3& v)
{
	return v.length();
}

inline f32
Vector3::length_sq(const Vector3& v)
{
	return v.length_sq();
}

inline Vector3
Vector3::normalize(const Vector3& v)
{
	Vector3 temp(v);
	temp.normalize();
	return temp;
}

inline f32
Vector3::distance(const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	temp -= v2;
	return temp.length();
}

inline f32
Vector3::distance_sq(const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	temp -= v2;
	return temp.length_sq();
}

inline f32
Vector3::dot(const Vector3& v1, const Vector3& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

inline Vector3
Vector3::cross(const Vector3& v1, const Vector3& v2)
{
	return Vector3(
		(v1.y * v2.z) - (v1.z * v2.y),
		(v1.z * v2.x) - (v1.x * v2.z),
		(v1.x * v2.y) - (v1.y * v2.x)
	);
}

inline Vector3
Vector3::lerp(const Vector3& v1, const Vector3& v2, f32 t)
{
	return Vector3((v1 * (1.0f - t)) + (v2 * t));
}

inline
Vector4::Vector4()
:	Float4( 0.0f, 0.0f, 0.0f, 0.0f )
{}

inline
Vector4::Vector4( f32 x, f32 y, f32 z, f32 w )
:	Float4( x, y, z, w )
{}

inline Vector4&
Vector4::set( f32 _x, f32 _y, f32 _z, f32 _w )
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

inline Vector4&
Vector4::normalize()
{
	f32 m = magnitude();
	if (m > 0.0f)
	{
		*this /= m;
	}
	return *this;
}

inline bool
Vector4::is_unit() const
{
	return length_sq() == 1.0f;
}

inline f32
Vector4::magnitude() const
{
	return length();
}

inline f32
Vector4::length() const
{
	return sqrt(length_sq());
}

inline f32
Vector4::length_sq() const
{
	return dot(*this, *this);
}

inline f32
Vector4::dot(const Vector4& v1, const Vector4& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
}

inline Vector4&
Vector4::operator += ( const Vector4& v )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &v );
	v1 = ::XMVectorAdd( v1, v2 );
	::XMStoreFloat4( this, v1 );
#elif	defined(USING_D3DX_MATH)
	::D3DXVec4Add( this, this, &v );
#else
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
#endif
	return *this;
}

inline Vector4&
Vector4::operator -= ( const Vector4& v )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &v );
	v1 = ::XMVectorSubtract( v1, v2 );
	::XMStoreFloat4( this, v1 );
#elif	defined(USING_D3DX_MATH)
	::D3DXVec4Subtract( this, this, &v );
#else
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
#endif
	return *this;
}

inline Vector4&
Vector4::operator *= ( const Vector4& v )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &v );
	v1 = ::XMVectorMultiply( v1, v2 );
	::XMStoreFloat4( this, v1 );
#else
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
#endif
	return *this;
}

inline Vector4&
Vector4::operator *= ( f32 s )
{
#if		defined(USING_XNA_MATH)
	::XMVECTOR v1 = ::XMLoadFloat4( this );
	::XMVECTOR v2 = ::XMLoadFloat4( &v );
	v1 = ::XMVectorScale( v1, s );
	::XMStoreFloat4( this, v1 );
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

inline Vector4&
Vector4::operator /= ( const Vector4& v )
{
	MH_ASSERT( v.x != 0.0f && v.y != 0.0f && v.z != 0.0f && v.w != 0.0f );
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;
	return *this;
}

inline Vector4&
Vector4::operator /= ( f32 f )
{
	MH_ASSERT( f != 0.0f );
	const float inv = 1.0f / f;
	x *= inv;
	y *= inv;
	z *= inv;
	w *= inv;
	return *this;
}

inline Vector4
Vector4::operator + () const
{
	return Vector4( *this );
}

inline Vector4
Vector4::operator - () const
{	
	return Vector4( -x, -y, -z, -w );
}

inline f32
Vector4::operator [] (int i) const
{
	MH_ASSERT(0 <= i && i <= 3);
	return *((float*)this + i);
}

inline Vector4
operator + ( const Vector4& v1, const Vector4& v2 )
{
	Vector4 ret = v1;
	ret += v2;
	return ret;
}

inline Vector4
operator - ( const Vector4& v1, const Vector4& v2 )
{
	Vector4 ret = v1;
	ret -= v2;
	return ret;
}

inline Vector4
operator * ( const Vector4& v1, const Vector4& v2 )
{
	Vector4 ret = v1;
	ret *= v2;
	return ret;
}

inline Vector4
operator * ( const Vector4& v, float s )
{
	Vector4 ret = v;
	ret *= s;
	return ret;
}

inline Vector4
operator * ( float s, const Vector4& v )
{
	Vector4 ret = v;
	ret *= s;
	return ret;
}

inline Vector4
operator / ( const Vector4& v1, const Vector4& v2 )
{
	Vector4 ret = v1;
	ret /= v2;
	return ret;
}

inline Vector4
operator / ( const Vector4& v, float s )
{
	const float inv = 1.0f / s;
	Vector4 ret = v;
	ret *= inv;
	return ret;
}

inline bool
operator == ( const Vector4& v1, const Vector4& v2 )
{
	return ( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w );
}

inline bool
operator != ( const Vector4& v1, const Vector4& v2 )
{
	return !( v1 == v2 );
}

#endif		/* _MH_MATH_VECTOR_INL_ */