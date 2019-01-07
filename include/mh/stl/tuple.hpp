#ifndef	_MH_STL_TUPPLE_HPP_
#define	_MH_STL_TUPPLE_HPP_

#include "utility.hpp"
#include <tuple>

/*
 *	C++11(TR1)에서 추가된 튜플 클래스
 *
 *	최소 10개 이상의 요소를 가지는 튜플을 준비해야함(개노가다...)
 *	뭔가 매크로로 처리 안되나...
 */
namespace Mh
{
	struct _Nil	{};
#if 0
	template<typename T1 = _Nil, typename T2 = _Nil,
		typename T3 = _Nil, typename T4 = _Nil,
		typename T5 = _Nil, typename T6 = _Nil,
		typename T7 = _Nil, typename T8 = _Nil,
		typename T9 = _Nil, typename T10>
	class tuple
	{
	public:
		// 생성자
		tuple();
		explicit tuple( const T1& );
		tuple( const tuple& );
		template<typename U1> tuple( const tuple<U1>& );

		// 배정 연산자
		tuple&	operator =	( const tuple& );
		template<typename U1> tuple&	operator =	( const tuple<U1>& );

	private:
		T1	elem1;
		T2	elem2;
		T3	elem3;
		T4	elem4;
		T5	elem5;
		T6	elem6;
		T7	elem7;
		T8	elem8;
		T9	elem9;
		T10	elem10;
	};


	template<typename T1, typename T2>
	class tuple
	{
	public:
		// 생성자
		tuple();
		explicit tuple( const T1&, const T2& );
		tuple( const tuple& );
		template<typename U1, typename U2> tuple( const tuple<U1, U2>& );
		template<typename U1, typename U2> tuple( const pair<U1, U2>& );

		// 배정 연산자
		tuple&	operator =	( const tuple& );
		template<typename U1, typename U2> tuple&	operator =	( const tuple<U1, U2>& );
		template<typename U1, typename U2> tuple&	operator =	( const pair<U1, U2>& );

	private:
		T1	elem1;
		T2	elem2;
	};
#endif
}		// namespace Mh

#endif	/* _MH_STL_TUPPLE_HPP_ */