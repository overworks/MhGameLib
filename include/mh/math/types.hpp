#ifndef	_MH_MATH_TYPES_H_
#define	_MH_MATH_TYPES_H_

#include <cassert>
#include <cmath>
#include <mh/types.hpp>

#ifndef		MH_ASSERT
#define		MH_ASSERT	assert
#endif		// MH_ASSERT

namespace Mh
{
	struct Float2
	{
		f32	x, y;
		
		Float2() {}
		Float2( f32 _x, f32 _y )
			: x(_x), y(_y) {}
	};

	struct Float3
	{
		f32 x, y, z;

		Float3() {}
		Float3( f32 _x, f32 _y, f32 _z )
			: x(_x), y(_y), z(_z) {}
	};

	struct Float4
	{
		f32 x, y, z, w;

		Float4() {}
		Float4( f32 _x, f32 _y, f32 _z, f32 _w )
			: x(_x), y(_y), z(_z), w(_w) {}
	};

	struct Vector2 : public Float2
	{
		Vector2();
		Vector2( f32 x, f32 y );

		// member functions
		Vector2&	set			( f32 x, f32 y );
		Vector2&	normalize	();
		f32			length		() const;
		f32			length_sq	() const;
		bool		is_unit		() const;

		// operator overloading
		Vector2		operator +	() const;
		Vector2		operator -	() const;
		Vector2&	operator +=	( const Vector2& );
		Vector2&	operator -=	( const Vector2& );
		Vector2&	operator *=	( const Vector2& );
		Vector2&	operator /=	( const Vector2& );
		Vector2&	operator *=	( f32 );
		Vector2&	operator /=	( f32 );
		f32			operator [] ( int ) const;

		// static members
		static	const Vector2	ZERO;
		static	const Vector2	ONE;
		static	const Vector2	X_AXIS;
		static	const Vector2	Y_AXIS;

		static	f32		length		( const Vector2& v );
		static	f32		length_sq	( const Vector2& v );
		static	Vector2	normalize	( const Vector2& v );
		static	f32		distance	( const Vector2& v1, const Vector2& v2 );
		static	f32		distance_sq	( const Vector2& v1, const Vector2& v2 );
		static	f32		dot			( const Vector2& v1, const Vector2& v2 );
		static	f32		cross		( const Vector2& v1, const Vector2& v2 );
		static	Vector2	lerp		( const Vector2& v1, const Vector2& v2, f32 t );
	};
	Vector2		operator +	( const Vector2&, const Vector2& );
	Vector2		operator -	( const Vector2&, const Vector2& );
	Vector2		operator /	( const Vector2&, const Vector2& );
	Vector2		operator *	( const Vector2&, float );
	Vector2		operator *	( float, const Vector2& );
	Vector2		operator /	( const Vector2&, float );	
	bool		operator ==	( const Vector2&, const Vector2& );
	bool		operator !=	( const Vector2&, const Vector2& );

	struct Vector3 : public Float3
	{
		Vector3();
		Vector3( f32 x, f32 y, f32 z );

		// member functions
		Vector3&	set( f32 x, f32 y, f32 z );
		Vector3&	normalize();
		f32			magnitude() const;
		f32			length() const;
		f32			length_sq() const;
		bool		is_unit() const;

		// operator overloading
		Vector3		operator +	() const;
		Vector3		operator -	() const;
		Vector3&	operator +=	( const Vector3& );
		Vector3&	operator -=	( const Vector3& );
		Vector3&	operator *=	( const Vector3& );
		Vector3&	operator /=	( const Vector3& );
		Vector3&	operator *=	( f32 );
		Vector3&	operator /=	( f32 );
		f32			operator [] ( int ) const;

		// static members
		static	const Vector3	ZERO;
		static	const Vector3	ONE;
		static	const Vector3	X_AXIS;
		static	const Vector3	Y_AXIS;
		static	const Vector3	Z_AXIS;

		static	f32		length		( const Vector3& v );
		static	f32		length_sq	( const Vector3& v );
		static	Vector3	normalize	( const Vector3& v );
		static	f32		distance	( const Vector3& v1, const Vector3& v2 );
		static	f32		distance_sq	( const Vector3& v1, const Vector3& v2 );
		static	f32		dot			( const Vector3& v1, const Vector3& v2 );
		static	Vector3	cross		( const Vector3& v1, const Vector3& v2 );
		static	Vector3	lerp		( const Vector3& v1, const Vector3& v2, f32 t );
	};
	Vector3		operator +	( const Vector3&, const Vector3& );
	Vector3		operator -	( const Vector3&, const Vector3& );
	Vector3		operator *	( const Vector3&, const Vector3& );
	Vector3		operator /	( const Vector3&, const Vector3& );
	Vector3		operator *	( const Vector3&, f32 );
	Vector3		operator *	( f32, const Vector3& );
	Vector3		operator /	( const Vector3&, f32 );
	bool		operator ==	( const Vector3&, const Vector3& );
	bool		operator !=	( const Vector3&, const Vector3& );

	typedef	Vector3	Vector;

	struct Vector4 : public Float4
	{
		Vector4();
		Vector4( f32 x, f32 y, f32 z, f32 w );

		// member functions
		Vector4&	set			( f32 x, f32 y, f32 z, f32 w );
		Vector4&	normalize	();
		bool		is_unit		() const;
		f32			magnitude	() const;
		f32			length		() const;
		f32			length_sq	() const;

		// operator overloading
		Vector4		operator +	() const;
		Vector4		operator -	() const;
		Vector4&	operator +=	( const Vector4& );
		Vector4&	operator -=	( const Vector4& );
		Vector4&	operator *=	( const Vector4& );
		Vector4&	operator /=	( const Vector4& );
		Vector4&	operator *=	( f32 );
		Vector4&	operator /=	( f32 );
		f32			operator [] ( int ) const;

		// static members
		static	const Vector4	ZERO;

		static	f32				dot		( const Vector4&, const Vector4& );
		static	Vector4			cross	( const Vector4&, const Vector4& );
	};
	Vector4		operator +	( const Vector4&, const Vector4& );
	Vector4		operator -	( const Vector4&, const Vector4& );
	Vector4		operator *	( const Vector4&, const Vector4& );
	Vector4		operator /	( const Vector4&, const Vector4& );
	Vector4		operator *	( const Vector4&, f32 );
	Vector4		operator *	( f32, const Vector4& );
	Vector4		operator /	( const Vector4&, f32 );
	bool		operator ==	( const Vector4&, const Vector4& );
	bool		operator !=	( const Vector4&, const Vector4& );

#include "vector.inl"

	struct Quaternion;

	/*
	 *	3x3 행렬
	 */
	struct Matrix3x3
	{
	public:		// 데이터 멤버
		f32 m[3][3];

		static const	Matrix3x3	ZERO;
		static const	Matrix3x3	IDENTITY;

	public:		// 멤버 함수
		Matrix3x3();
		Matrix3x3( f32 _00, f32 _01, f32 _02,
				f32 _10, f32 _11, f32 _12,
				f32 _20, f32 _21, f32 _22 );

		explicit Matrix3x3( f32 _m[3][3] );
		Matrix3x3( const Quaternion& );

		Matrix3x3&	transpose	();
		Matrix3x3&	invert		();
		
		Matrix3x3&	multiply	( const Matrix3x3& );
		Matrix3x3&	scale		( f32 );
		Matrix3x3&	scale		( f32 x, f32 y, f32 z );
		Matrix3x3&	scale		( const Vector3& );
		Matrix3x3&	rotate		( const Quaternion& );
		Matrix3x3&	rotate		( const Matrix3x3& );
		Matrix3x3&	rotate		( const Vector3& axis, f32 angle );

		Matrix3x3&	transform	( const Vector3& );

		bool		operator ==	( const Matrix3x3& ) const;
		bool		operator !=	( const Matrix3x3& ) const;
		
		Matrix3x3	operator +	() const;
		Matrix3x3	operator -	() const;

		Matrix3x3&	operator +=	( const Matrix3x3& );
		Matrix3x3&	operator -= ( const Matrix3x3& );
		Matrix3x3&	operator *=	( const Matrix3x3& );
		Matrix3x3&	operator *=	( f32 );
		Matrix3x3&	operator /=	( f32 );

		Matrix3x3	operator +	( const Matrix3x3& ) const;
		Matrix3x3	operator -	( const Matrix3x3& ) const;
		Matrix3x3	operator *	( const Matrix3x3& ) const;
		Matrix3x3	operator *	( f32 ) const;
		Matrix3x3	operator /	( f32 ) const;
	};

	struct Matrix4x4
	{
	public:		// 데이터 멤버
		f32	m[4][4];

		static const	Matrix4x4	ZERO;
		static const	Matrix4x4	IDENTITY;

	public:		// 멤버 함수	
		Matrix4x4( f32 _00 = 1.0f, f32 _01 = 0.0f, f32 _02 = 0.0f, f32 _03 = 0.0f,
				f32 _10 = 0.0f, f32 _11 = 1.0f, f32 _12 = 0.0f, f32 _13 = 0.0f,
				f32 _20 = 0.0f, f32 _21 = 0.0f, f32 _22 = 1.0f, f32 _23 = 0.0f,
				f32 _30 = 0.0f, f32 _31 = 0.0f, f32 _32 = 0.0f, f32 _33 = 1.0f );
		Matrix4x4( const Vector3& scale, const Vector3& rotation, const Vector3& translation );
		Matrix4x4( const Quaternion& );

		Matrix4x4&	transpose		();
		Matrix4x4&	invert			();
		bool		is_identity		() const;

		Matrix4x4&	multiply		( const Matrix4x4& );

		Matrix4x4&	translate		( const Vector3& );
		
		Matrix4x4&	rotate			( f32 pitch, f32 yaw, f32 roll );
		Matrix4x4&	rotate			( const Vector3& pitch_yaw_roll ); 
		Matrix4x4&	rotate			( const Vector3& axis, f32 radius );
		Matrix4x4&	rotate			( const Quaternion& );
		Matrix4x4&	scale			( const Vector3& );
		
		Matrix4x4&	set_scale		( const Vector3& );
		Matrix4x4&	set_rotation	( const Vector3& );
		Matrix4x4&	set_translation	( const Vector3& );
		Vector3		get_scale		() const;
		Vector3		get_rotation	() const;
		Vector3		get_translation	() const;

		Vector3		transform		( const Vector3& );
		
		//	이하 연산자 오버로딩
		bool		operator ==		( const Matrix4x4& ) const;
		bool		operator !=		( const Matrix4x4& ) const;
		Matrix4x4&	operator *=		( const Matrix4x4& );
		Matrix4x4	operator *		( const Matrix4x4& ) const;
		Vector3		operator *		( const Vector3& );
		
	};

	typedef	Matrix4x4	Matrix;

#include "matrix.inl"

	/*!
	 *	\brief		사원수 구조체
	 *	\details	회전을 표현하기 위한 사원
	 */
	struct Quaternion : public Float4
	{
		/*!
		 *	\brief		생성자
		 *	\details	성분을 초기화하지 않음
		 */
		Quaternion();
		/*!
		 *	\brief		생성자
		 *	\details	성분을 명시적으로 초기화
		 */
		Quaternion( f32 x, f32 y, f32 z, f32 w );
		/*!
		 *	\brief		생성자
		 *	\details	축-각값으로 초기화
		 */
		Quaternion( const Vector3& axis, f32 angle );
		/*!
		 *	\brief		오일러각으로 초기화
		 */
		Quaternion( f32 pitch, f32 yaw, f32 roll );
		/*!
		 *	\brief		3x3 행렬로 초기화
		 */
		explicit Quaternion( const Matrix3x3& );
		/*!
		 *	\brief		4x4 행렬로 초기화
		 */
		explicit Quaternion( const Matrix& matrix );
		Quaternion( const Vector3& origin, const Vector3& destination );

		Quaternion&	set			( f32 x, f32 y, f32 z, f32 w );
		Quaternion&	set			( const Vector3& axis, f32 angle );
		Quaternion&	set			( f32 pitch, f32 yaw, f32 roll );
		Quaternion& set			( const Matrix& matrix );
		Quaternion&	set			( const Vector3& origin, const Vector3& destination );
		Quaternion&	rotate		( const Quaternion& rotation );
		Quaternion&	rotate		( const Vector3& axis, f32 angle );
		Quaternion& rotate		( f32 pitch, f32 yaw, f32 roll );
		Quaternion&	rotate		( const Matrix& matrix );
		Quaternion&	normalize	();
		Quaternion&	invert		();
		f32			length		() const;
		f32			length_sq	() const;
		bool		is_unit		() const;
		Quaternion	exp			() const;
		Quaternion	ln			() const;
		Vector3		rotate_vector( const Vector3& ) const;

		void		to_matrix	( Matrix& matrix ) const;
		void		to_axis_angle( Vector3& axis, f32& angle ) const;
		void		to_pitch_yaw_roll( f32& pitch, f32& yaw, f32& roll ) const;

		Quaternion	operator +	() const;
		Quaternion	operator -	() const;
		Quaternion&	operator +=	( const Quaternion& );
		Quaternion&	operator -=	( const Quaternion& );
		Quaternion&	operator *=	( const Quaternion& );
		Quaternion&	operator *=	( f32 );
		Quaternion&	operator /=	( f32 );

		// static members
		static	const Quaternion	IDENTITY;

		static	Quaternion	normalize		( const Quaternion& q );
		static	Quaternion	conjugate		( const Quaternion& q );
		static	Quaternion	invert			( const Quaternion& q );
		static	Quaternion	exp				( const Quaternion& q );
		static	Quaternion	ln				( const Quaternion& q );
		static	Vector3		rotate_vector	( const Quaternion& q, const Vector3& v );
		static	f32			distance		( const Quaternion& q1, const Quaternion& q2 );
		static	Quaternion	slerp			( const Quaternion& q1, const Quaternion& q2, f32 t );
	};
	bool		operator ==	( const Quaternion&, const Quaternion& );
	bool		operator !=	( const Quaternion&, const Quaternion& );
	Quaternion	operator +	( const Quaternion&, const Quaternion& );
	Quaternion	operator -	( const Quaternion&, const Quaternion& );
	Quaternion	operator *	( const Quaternion&, const Quaternion& );
	Quaternion	operator *	( const Quaternion&, float );
	Quaternion	operator *	( float, const Quaternion& );
	Quaternion	operator /	( const Quaternion&, float );

#include "quaternion.inl"

	/*!
	 *	\brief		구(球) 구조체
	 *	\details	Float4 구조체를 상속받아 구현된 구조체
	 */
	struct Sphere : public Float4
	{
		/*!
		 *	\brief		생성자
		 *	\details	0으로 초기화
		 */
		Sphere();
		/*!
		 *	\brief		생성자
		 *	\details	4개의 부동소수점으로 초기화
		 *	\param	x	x좌표
		 *	\param	y	y좌표
		 *	\param	z	z좌표
		 *	\param	r	구의 반경
		 */
		Sphere( f32 x, f32 y, f32 z, f32 r );
		/*!
		 *	\brief		생성자
		 *	\details	3차원 벡터와 반경으로 초기화
		 *	\param	p	좌표
		 *	\param	r	구의 반경
		 */
		Sphere( const Vector3& p, f32 r );
		/*!
		 *	\brief		재설정
		 *	\details	구의 정보 재설정
		 *	\return		자기 자신의 참조
		 *	\param	x	x좌표
		 *	\param	y	y좌표
		 *	\param	z	z좌표
		 *	\param	r	구의 반경
		 */
		Sphere&		set( f32 x, f32 y, f32 z, f32 r );
		/*!
		 *	\brief		재설정
		 *	\details	구의 정보 재설정
		 *	\return		자기 자신의 참조
		 *	\param	p	좌표
		 *	\param	r	구의 반경
		 */
		Sphere&		set( const Vector3& p, f32 r );
		/*!
		 *	\brief		위치 재설정
		 *	\details	구의 위치 재설정
		 *	\return		자기 자신의 참조
		 *	\param	p	좌표
		 */
		Sphere&		set_position( const Vector3& p );
		/*!
		 *	\brief		위치 재설정
		 *	\details	구의 위치 재설정
		 *	\return		자기 자신의 참조
		 *	\param	x	x좌표
		 *	\param	y	x좌표
		 *	\param	z	x좌표
		 */
		Sphere&		set_position( f32 x, f32 y, f32 z );
		/*!
		 *	\brief		반경 재설정
		 *	\details	구의 반경 재설정
		 *	\return		자기 자신의 참조
		 *	\param	r	반경
		 */
		Sphere&		set_radius( f32 r );
		/*!
		 *	\brief		== 연산자
		 *	\details	두 개체의 좌표와 크기가 같으면 true, 아니면 false를 리턴
		 *	\return		판단 결과
		 *	\param	s	비교할 개체
		 */
		bool		operator == ( const Sphere& s ) const;
		/*!
		 *	\brief		!= 연산자
		 *	\details	두 개체의 좌표와 크기가 다르면 true, 같으면 false를 리턴
		 *	\return		판단 결과
		 *	\param	s	비교할 개체
		 */
		bool		operator != ( const Sphere& s ) const;
		/*!
		 *	\brief		교차판정
		 *	\details	두 개체에 겹쳐지는 부분이 있으면 true, 없으면 false를 리턴
		 *	\return		판단 결과
		 *	\param	lhs	첫번째 개체
		 *	\param	rhs	두번째 개체
		 */
		static bool	intersect( const Sphere& lhs, const Sphere& rhs );
	};

#include "sphere.inl"

	struct Plane : public Float4
	{
		Plane( f32 a, f32 b, f32 c, f32 d );
		Plane( const Vector3& point, const Vector3& normal );
		Plane( const Vector3& point1, const Vector3& point2, const Vector3& point3 );

		Plane&		set			( f32 a, f32 b, f32 c, f32 d );
		Plane&		set			( const Vector3& point, const Vector3& normal );
		Plane&		set			( const Vector3& point1, const Vector3& point2, const Vector3& point3 );
		Plane&		normalize	();
		f32			dot			( const Vector4& point ) const;
		f32			dot_coord	( const Vector3& point ) const;

		bool		operator ==	( const Plane& rhs ) const;
		bool		operator !=	( const Plane& rhs ) const;

		static f32	distance( const Plane& plane, const Vector3& point );
	};

#include "plane.inl"

	/*!
	 *	축 정렬 경계상자(Axis-Aligned Bounding Box)
	 */
	struct AABB
	{
		Vector3	maxima;
		Vector3 minima;	
	};

	bool intersect( const AABB&, const AABB& );


	/*!
	 *	3차원 선 구조체
	 */
	struct Line3
	{
		// data member
		Vector3	direction;
		Vector3	origin;

		Line3( const Vector3& direction, const Vector3& origin );

		Line3&	normalize();
	};

#include "line.inl"

	/*!
	 *	3차원 삼각형 구조체
	 */
	struct Triangle
	{
		// data members
		Vector3		point1, point2, point3;

		// constructor
		Triangle				( const Triangle& point1,  const Triangle& point2, const Triangle& point3 );
		
		// member functions
		Triangle&	set			( const Triangle& point1,  const Triangle& point2, const Triangle& point3 );
		bool		is_valid	() const;
		Plane		to_plane	() const;

		// static members
		Plane		to_plain	( const Triangle& triangle );
	};

	/*!
	 *	2차원 좌표계용 좌표 구조체
	 */
	template<typename T>
	struct Point
	{
		//	data members
		T	x, y;

		//	constructor
		Point				( T x = 0, T y = 0 );
		//	member functions
		Point&	set			( T x, T y );

		//	static members
		static	T			length		( const Point& p1, const Point& p2 );
		static	T			length_sq	( const Point& p1, const Point& p2 );
		static	Point<T>	center		( const Point& p1, const Point& p2 );
	};
	typedef		Point<s32>	PointI;
	typedef		Point<f32>	PointF;

#include "point.inl"

	/*!
	 *	2차원 좌표계용 사각형 구조체
	 */
	template<typename T>
	struct Rect
	{
		//	data members
		Point<T>	upper_left, lower_right;

		//	constructors
		Rect					();
		Rect					( T left, T top, T right, T bottom );
		Rect					( const Point<T>& upper_left, const Point<T>& lower_right );

		//	member functions
		Rect&		set			( T left, T top, T right, T bottom );
		Rect&		set			( const Point<T>& upper_left, const Point<T>& lower_right );
		//Rect&		reset		();
		Rect&		repair		();
		T			width		()	const;
		T			height		()	const;
		Point<T>	center		()	const;
		bool		is_valid	()	const;
		bool		is_point_inside		( const Point<T>& point ) const;
		bool		is_rect_collided	( const Rect<T>& rect ) const;
	};
	typedef		Rect<s32>	RectI;
	typedef		Rect<f32>	RectF;

#include "rect.inl"

	struct ColorF;

	/*!
	 *	정수형 색 구조체
	 */
	struct ColorI
	{
		/*!
		 *	\brief		컬러값
		 *	\details	알파, 적색, 녹색, 청색에 각 8비트씩 배당하여 저장한 32비트 부호없는 정수
		 */
		u8	r, g, b, a;

		/*!
		 *	\brief		생성자
		 *	\details	8비트 r,g,b,a 값을 입력받아 초기화
		 *	\param	r	적색값
		 *	\param	g	녹색값
		 *	\param	b	황색값
		 *	\param	a	알파값
		 */
		ColorI				( u8 r = 0, u8 g = 0, u8 b = 0, u8 a = 255 );
		/*!
		 *	\brief		생성자
		 *	\details	알파, 적, 녹, 황의 순서의 32비트 값으로 초기화
		 */
		explicit ColorI		( u32 rgba );
		/*!
		 *	\brief		생성자
		 *	\details	ColorF 값으로 초기화
		 */
		explicit ColorI		( const ColorF& colorf );

		/*!
		 *	\brief		색 재설정
		 *	\details	8비트 r,g,b,a 값으로 설정
		 *	\param	r	적색값
		 *	\param	g	녹색값
		 *	\param	b	황색값
		 *	\param	a	알파값
		 *	\return		자기 자신의 참조
		 */
		ColorI&		set		( u8 r, u8 g, u8 b, u8 a = 255 );

		/*!
		 *	\brief			색 재설정
		 *	\details		32비트 부호없는 정수형으로 설정
		 *	\param	rgba	RGBA 순서의 32비트 부호없는 정수형
		 *	\return			자기 자신의 참조
		 */
		ColorI&		set		( u32 rgba );

		/*!
		 *	\brief			색 재설정
		 *	\details		ColorF 값으로 설정
		 *	\param	colorf	부동소수형 컬러값
		 *	\return			자기 자신의 참조
		 */
		ColorI&		set		( const ColorF& colorf );
		/*!
		 *	\brief		색 반전
		 *	\details	r, g, b값을 반전. 알파값은 그대로.
		 *	\return		자기 자신의 참조
		 */
		ColorI&		invert	();

		u8&			operator [] ( size_t index );
		u8			operator [] ( size_t index ) const;

		/*
		 *	정적 멤버
		 */
		static const ColorI WHITE;		//!< 백색
		static const ColorI GRAY;		//!< 회색
		static const ColorI BLACK;		//!< 흑색
		static const ColorI RED;		//!< 적색
		static const ColorI GREEN;		//!< 녹색
		static const ColorI BLUE;		//!< 청색
		static const ColorI YELLOW;		//!< 황색
		static const ColorI CYAN;		//!< 사이언
		static const ColorI MAGENTA;	//!< 마젠타

		/*!
		 *	\brief		부호없는 32비트 정수로 생성
		 *	\param		a,r,g,b 순서의 부호없는 32비트 정수
		 *	\return		ColorI 로 바뀐 값
		 */
		static ColorI		from_argb	( u32 argb );
		/*!
		 *	\brief		부호없는 32비트 정수로 생성
		 *	\param		r,g,b,a 순서의 부호없는 32비트 정수
		 *	\return		ColorI 로 바뀐 값
		 */
		static ColorI		from_rgba	( u32 rgba );
		/*!
		 *	\brief		부호없는 32비트 정수로 생성
		 *	\param		x,r,g,b 순서의 부호없는 32비트 정수(25~32비트는 무시)
		 *	\return		ColorI 로 바뀐 값
		 */
		static ColorI		from_xrgb	( u32 xrgb );
		/*!
		 *	\brief		부호없는 32비트 정수로 생성
		 *	\param		r,g,b,x 순서의 부호없는 32비트 정수(1~8비트는 무시)
		 *	\return		ColorI 로 바뀐 값
		 */
		static ColorI		from_rgbx	( u32 rgbx );
		/*!
		 *	\brief		부호없는 32비트 정수로 출력
		 *	\param		출력할 ColorI 개체
		 *	\return		a,r,g,b 순서의 부호없는 32비트 정수
		 */
		static u32			to_argb		( const ColorI& colori );
		/*!
		 *	\brief		부호없는 32비트 정수로 출력
		 *	\param		출력할 ColorI 개체
		 *	\return		r,g,b,a 순서의 부호없는 32비트 정수
		 */
		static u32			to_rgba		( const ColorI& colori );
		/*!
		 *	\brief		부호없는 32비트 정수로 출력
		 *	\param		출력할 ColorI 개체
		 *	\return		x,r,g,b 순서의 부호없는 32비트 정수(x는 255로 고정)
		 */
		static u32			to_xrgb		( const ColorI& colori );
		/*!
		 *	\brief		부호없는 32비트 정수로 출력
		 *	\param		출력할 ColorI 개체
		 *	\return		a,r,g,b 순서의 부호없는 32비트 정수(x는 255로 고정)
		 */
		static u32			to_rgbx		( const ColorI& colori );
		/*!
		 *	\brief		색반전(비멤버 함수 버전)
		 *	\details	원본 ColorI 개체
		 *	\param		반전된 ColorI 개체
		 */
		static ColorI		invert		( const ColorI& colori );
	};
	/*!
	 *	\memberof	ColorF
	 *	\brief		== 연산자
	 */
	bool	operator ==		( const ColorI& lhs, const ColorI& rhs );
	/*!
	 *	\memberof	ColorF
	 *	\brief		!= 연산자
	 */
	bool	operator !=		( const ColorI& lhs, const ColorI& rhs );


	/*!
	 *	부동소수형 색 구조체
	 */
	struct ColorF
	{
		/*!
		 *	0부터 1사이의 값을 갖는 부동소수점 수치
		 */
		f32		r, g, b, a;

		/*!
		 *	\brief		생성자
		 *	\details	r,g,b,a 값을 입력받아 초기화. 기본은 검은색
		 *	\param	r	적색값
		 *	\param	g	녹색값
		 *	\param	b	황색값
		 *	\param	a	알파값
		 */
		ColorF				( f32 r = 0.0f, f32 g = 0.0f, f32 b = 0.0f, f32 a = 1.0f );
		/*!
		 *	\brief			생성자
		 *	\details		적, 녹, 황, 알파의 순서의 32비트 값으로 초기화
		 *	\param	argb	부호없는 32비트 정수
		 */
		explicit ColorF		( u32 rgba );
		/*!
		 *	\brief			생성자
		 *	\details		ColorI 값으로 초기화
		 *	\param	colori	ColorI 개체
		 */
		explicit ColorF		( const ColorI& colori );

		/*!
		 *	\brief			색 재설정
		 *	\details		0 - 1사이의 값을 갖는 부동소수점 수치를 입력
		 *	\param	r		적색값
		 *	\param	g		녹색값
		 *	\param	b		황색값
		 *	\param	a		알파값
		 *	\return			자기 자신의 참조
		 */
		ColorF&		set		( f32 r, f32 g, f32 b, f32 a = 1.0f );
		/*!
		 *	\brief			색 재설정
		 *	\details		알파, 적, 녹, 황의 순서의 32비트 값으로 설정
		 *	\param	argb	부호없는 32비트 정수
		 *	\return			자기 자신의 참조
		 */
		ColorF&		set		( u32 rgba );
		/*!
		 *	\brief			색 재설정
		 *	\details		ColorI 값으로 설정
		 *	\param	colori	ColorI 개체
		 *	\return			자기 자신의 참조
		 */
		ColorF&		set		( const ColorI& colori );
		/*!
		 *	\brief			색반전
		 *	\details		r,g,b 값을 반전. 알파값은 변하지 않음
		 *	\param			자기 자신의 참조
		 */
		ColorF&		invert	();
		/*!
		 *	\brief			0 - 1 사이의 값으로 고정
		 *	\details		0 이하이거나 1 이상인 수치를 재조정
		 *	\param			자기 자신의 참조
		 */
		ColorF&		saturate();

		f32&	operator []	( size_t index );
		f32		operator []	( size_t index ) const;

		/*
		 *	정적 멤버
		 */
		static const ColorF WHITE;		//!< 백색
		static const ColorF GRAY;		//!< 회색
		static const ColorF BLACK;		//!< 흑색
		static const ColorF RED;		//!< 적색
		static const ColorF GREEN;		//!< 녹색
		static const ColorF BLUE;		//!< 청색
		static const ColorF YELLOW;		//!< 황색
		static const ColorF CYAN;		//!< 사이언
		static const ColorF MAGENTA;	//!< 마젠타

		/*!
		 *	\brief		부호없는 32비트 정수로 생성
		 *	\param		a,r,g,b 순서의 부호없는 32비트 정수
		 *	\return		생성된 ColorF 개체
		 */
		static ColorF		from_argb	( u32 argb );
		/*!
		 *	\brief		부호없는 32비트 정수로 생성
		 *	\param		r,g,b,a 순서의 부호없는 32비트 정수
		 *	\return		생성된 ColorF 개체
		 */
		static ColorF		from_rgba	( u32 rgba );
		/*!
		 *	\brief		부호없는 32비트 정수로 생성
		 *	\param		x,r,g,b 순서의 부호없는 32비트 정수(25~32비트는 무시)
		 *	\return		생성된 ColorF 개체
		 */
		static ColorF		from_xrgb	( u32 xrgb );
		/*!
		 *	\brief		부호없는 32비트 정수로 생성
		 *	\param		r,g,b,x 순서의 부호없는 32비트 정수(1~8비트는 무시)
		 *	\return		생성된 ColorF 개체
		 */
		static ColorF		from_rgbx	( u32 rgbx );
		/*!
		 *	\brief		부호없는 32비트 정수로 출력
		 *	\param		출력할 ColorF 개체
		 *	\return		a,r,g,b 순서의 부호없는 32비트 정수
		 */
		static u32			to_argb		( const ColorF& colori );
		/*!
		 *	\brief		부호없는 32비트 정수로 출력
		 *	\param		출력할 ColorF 개체
		 *	\return		r,g,b,a 순서의 부호없는 32비트 정수
		 */
		static u32			to_rgba		( const ColorF& colori );
		/*!
		 *	\brief		부호없는 32비트 정수로 출력
		 *	\param		출력할 ColorF 개체
		 *	\return		x,r,g,b 순서의 부호없는 32비트 정수(x는 255로 고정)
		 */
		static u32			to_xrgb		( const ColorF& colori );
		/*!
		 *	\brief		부호없는 32비트 정수로 출력
		 *	\param		출력할 ColorF 개체
		 *	\return		x,r,g,b 순서의 부호없는 32비트 정수(x는 255로 고정)
		 */
		static u32			to_rgbx		( const ColorF& colori );
		/*!
		 *	\brief		색반전(비멤버 함수 버전)
		 *	\param		원본 ColorF 개체
		 *	\return		반전된 ColorF 개체
		 */
		static ColorF		invert		( const ColorF& colori );
#if 0
		/*!
		 *	\brief		0 - 1 사이의 값으로 고정(비멤버 함수 버전)
		 *	\details	0 이하이거나 1 이상인 수치를 재조정한 개체를 출력
		 *	\param		원본 ColorF 개체
		 *	\return		조정된 ColorF 개체
		 */
		static ColorF		saturate	( const ColorF& colori );
#endif
	};
	bool	operator ==		( const ColorF& lhs, const ColorF& rhs );
	bool	operator !=		( const ColorF& lhs, const ColorF& rhs );

#include "color.inl"

	/*!
	 *	\brief		Time 클래스
	 *	\warning	고정 프레임에서만 유효
	 */
	class Time
	{
	public:
		//!	생성자(0으로 초기화)
		Time();
		//!	생성자(초 단위로 초기화)
		explicit Time( f32 second );
		//!	내부 카운트 취득
		s32		get_count	() const;
		//!	초 단위로 취득
		f32		to_second	() const;
		//!	프레임 단위로 취득
		s32		get_frame	() const;

		//! + 연산자(사본)
		Time	operator +	() const;
		//! - 연산자(역수)
		Time	operator -	() const;
		//!	전위증가연산자(1프레임 가산)
		Time&	operator ++	();
		//!	전위감소연산자(1프레임 감산)
		Time&	operator --	();
		//! 후위증가연산자(리턴 후 1프레임 가산)
		Time	operator ++	( int );
		//! 후위증가연산자(리턴 후 1프레임 감산)
		Time	operator --	( int );
		//! += 연산자(시간 단위)
		Time&	operator +=	( const Time& time );
		//! -= 연산자(시간 단위)
		Time&	operator -=	( const Time& time );
		//! += 연산자(프레임 단위)
		Time&	operator +=	( s32 frame );
		//! -= 연산자(프레임 단위)
		Time&	operator -=	( s32 frame );
		//! *= 연산자(곱셈)
		Time&	operator *=	( f32 s );
		//! /= 연산자(나눗셈)
		Time&	operator /=	( f32 s );

		//! 0초
		static const Time	ZERO;
		//! 1초
		static const Time	SECOND;
		//! 1분(60초)
		static const Time	MINUTE;
		//! 1시간(60분)
		static const Time	HOUR;
		//! 1일(24시간)
		static const Time	DAY;

		//!	프레임율 변경
		static void	set_frame_rate	( u32 frame_rate );
		//!	현재 프레임율 취득
		static u32	get_frame_rate	();
		//!	절대값 취득
		static Time	abs				( const Time& time );

	private:
		//!	열거형 상수
		enum ConstValue
		{
			DEF_FRAME_RATE	= 60,
			COUNT_OF_SECOND = 300,
		};
		//!	내부 카운트
		s32			m_count;
		//!	프레임율
		static u32	s_frame_rate;
		//!	프레임당 카운트
		static u32	s_count_per_frame;
	};
	/*!
	 *	\memberof	Time
	 *	\brief		== 연산자
	 */
	bool	operator ==	( const Time& lhs, const Time& rhs );
	/*!
	 *	\memberof	Time
	 *	\brief		!= 연산자
	 */
	bool	operator !=	( const Time& lhs, const Time& rhs );
	/*!
	 *	\memberof	Time
	 *	\brief		+ 연산자
	 */
	Time	operator +	( const Time& lhs, const Time& rhs );
	/*!
	 *	\memberof	Time
	 *	\brief		- 연산자
	 */
	Time	operator -	( const Time& lhs, const Time& rhs );
	/*!
	 *	\memberof	Time
	 *	\brief		* 연산자
	 */
	Time	operator *	( const Time& lhs, f32 rhs );
	/*!
	 *	\memberof	Time
	 *	\brief		* 연산자
	 */
	Time	operator *	( f32 rhs, const Time& lhs );
	/*!
	 *	\memberof	Time
	 *	\brief		/ 연산자
	 */
	Time	operator /	( const Time& lhs, f32 rhs );

}

#endif	// _MH_MATH_TYPES_H_