#ifndef	_MH_RATIO_HPP_
#define	_MH_RATIO_HPP_

#include "prerequisite.h"

namespace Mh
{
	typedef	long long intmax_t;		// 나중에 헤더를 따로 만듬

	template<intmax_t Num, intmax_t Denom = 1>
	class ratio
	{
	public:
		typedef	ratio	type;

	public:
#if ((_MH_COMPILER_SUPPORT_ & _MH_CPP11_FEATURE_CONSTEXPR_) != 0)
		constexpr static intmax_t num = Num;
		constexpr static intmax_t den = Denom;
#else
		enum
		{
			num = Num,
			den = Denom,
		};
#endif
	};

#if 0
	template<typename R1, typename R2>
	using ratio_add = ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;

	template<typename R1, typename R2>
	using ratio_subtract = ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;

	template<typename R1, typename R2>
	using ratio_multiply = ratio<R1::num * R2::num, R1::den * R2::den>;

	template<typename R1, typename R2>
	using ratio_divide = ratio<R1::num * R2::den, R1::den * R2::num>;
#endif

//	typedef	ratio<1, 1000000000000000000000000>	yocto;
//	typedef	ratio<1, 1000000000000000000000> zepto;
	typedef	ratio<1, 1000000000000000000>	atto;
	typedef	ratio<1, 1000000000000000>	femto;
	typedef	ratio<1, 1000000000000>	pico;
	typedef	ratio<1, 1000000000>	nano;
	typedef	ratio<1, 1000000>	micro;
	typedef	ratio<1, 1000>	milli;
	typedef	ratio<1, 100>	centi;
	typedef	ratio<1, 10>	deci;
	typedef	ratio<10, 1>	deca;
	typedef	ratio<100, 1>	hecto;
	typedef	ratio<1000, 1>	kilo;
	typedef	ratio<1000000, 1>	mega;
	typedef	ratio<1000000000, 1>	giga;
	typedef	ratio<1000000000000, 1>	tera;
	typedef	ratio<1000000000000000, 1>	peta;
	typedef	ratio<1000000000000000000, 1>	exa;
//	typedef	ratio<1000000000000000000000, 1>	zetta;
//	typedef	ratio<1000000000000000000000000, 1>	yotta;

}

#endif	/* _MH_RATIO_HPP_ */