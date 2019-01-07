#ifndef	_MH_TIMER_HPP_
#define	_MH_TIMER_HPP_

#include "types.hpp"

namespace Mh
{
	class Timer
	{
	public:
		Timer() {}
		virtual ~Timer() {}

		/**
		 *	게임 시작 후 경과한 시간. 초 단위
		 */
		virtual f32		get_game_time() const = 0;

		/**
		 *	지난 프레임으로 지난 시간. 초 단위
		 */
		virtual f32		get_delta_time() const = 0;

		virtual void	reset() = 0;	// 메시지 루프 들어가기 전에 호출
		virtual void	start() = 0;	// 타이머를 다시 개시할 때 호출
		virtual void	stop() = 0;		// 정지되었을때 호출
		virtual void	tick() = 0;		// 매 프레임 호출
	};

}		// namespace Mh

#endif	/* _MH_TIMER_HPP_ */