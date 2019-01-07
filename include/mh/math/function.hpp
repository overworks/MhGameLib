#ifndef	_MH_MATH_FUNCTION_HPP_
#define	_MH_MATH_FUNCTION_HPP_

#include "types.hpp"

namespace Mh
{
	// 수학 함수
	s32 abs		( s32 x );
	f32 abs		( f32 x );
	f64 abs		( f64 x );
	f32 sqrt	( f32 x );
	f64 sqrt	( f64 x );
	f32 sin		( f32 x );
	f64 sin		( f64 x );
	f32 cos		( f32 x );
	f64 cos		( f64 x );
	f32 asin	( f32 x );
	f64 asin	( f64 x );
	f32 acos	( f32 x );
	f64 acos	( f64 x );
	f32 atan	( f32 x );
	f64 atan	( f64 x );
	f32 atan2	( f32 y, f32 x );
	f64 atan2	( f64 y, f64 x );

	f32	absf	( f32 x );

	// 캐스팅
#if 0
	s32	f2s		( f32 x );
	f32	s2f		( s32 x );
#endif

	// 거리
	f32 distance( const Line3& line, const Vector3& point );
	f32 distance( const Vector3& point, const Line3& line );

	// 충돌 판정
	bool intersect( const Sphere& s1, const Sphere& s2 );
	bool intersect( const Sphere& s, const Line3& l );
	bool intersect( const Triangle& s, const Triangle& );


#include "function.inl"

}		// namespace Mh

#endif	/* _MH_MATH_FUNCTION_HPP_ */