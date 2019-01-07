#ifndef	_MH_CHRONO_HPP_
#define	_MH_CHRONO_HPP_

#include "ratio.hpp"

namespace Mh
{
	namespace chrono
	{
		template<typename Rep, typename Period = ratio<1>>
		class duration
		{
		public:
			typedef	Rep				rep;
			typedef	Period::type	period;

			/*!
			 *	\brief 기본 생성자
			 */
			constexpr duration() = default;
			duration(const duration&);
			template<typename Rep2>	constexpr explicit duration(const Rep2& r);
			template<typename Rep2, typename Period2> constexpr duration(const duration<Rep2, Period2>& d);
		};

		template<typename Clock, typename Duration = typename Clock::duration>
		class time_point;

		template<typename Clock, typename Duration = typename Clock::duration>
		class time_point
		{
		public:
			typedef	Clock				clock;
			typedef	Duration			duration;
			typedef	duration::rep		rep;
			typedef	duration::period	period;

		public:


		};

		//template<typename Rep, class Period = std::radio<1>

		class system_clock
		{
		public:
			static time_point<system_clock>	now();

		};

		class steady_clock
		{
		public:
			static time_point<steady_clock>	now();
			static bool			is_steady();
		};

		class high_resolution_clock
		{
		public:
			typedef	time_point<high_resolution_clock>	time_point;

			static time_point	now();
			static bool			is_steady();
		};
	}
}

#endif	/* _MH_CHRONO_HPP_ */