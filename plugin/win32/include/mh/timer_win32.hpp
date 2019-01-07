#ifndef _MH_TIMER_WIN32_HPP_
#define _MH_TIMER_WIN32_HPP_

#include <mh/timer.hpp>

namespace Mh
{
	class TimerWin32 : public Timer
	{
	public:
		TimerWin32();
		virtual ~TimerWin32();

		virtual	f32		get_game_time() const;
		virtual	f32		get_delta_time() const;

		virtual void	reset();
		virtual void	start();
		virtual void	stop();
		virtual void	tick();

	private:
		bool	m_stopped;			// 타이머 중지 상태
		u32		m_start_time;		// 타이머 시작(생성) 시각
		u32		m_total_idle_time;	// 중지시간의 합
		u32		m_previous_time;	// 이전 틱에서의 시각
		u32		m_current_time;		// 현 택에서의 시각
		u32		m_paused_time;		// 중지했을 당시의 시각
		f32		m_delta_time;		// 델타
	};
}

#endif /* _MH_TIMER_WIN32_HPP_ */