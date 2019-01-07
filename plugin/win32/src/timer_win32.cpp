#include <Windows.h>
#include <mh/timer_win32.hpp>

/**
 *	https://bell0bytes.eu/the-game-loop/ 를 참고
 */
namespace Mh
{
	TimerWin32::TimerWin32()
		: m_stopped(false), m_start_time(0), m_total_idle_time(0), m_previous_time(0), m_current_time(0), m_paused_time(0), m_delta_time(0.0f)
	{

	}

	TimerWin32::~TimerWin32()
	{

	}

	f32 TimerWin32::get_game_time() const
	{
		u32 target_time = (!m_stopped ? m_current_time : m_paused_time);
		return (target_time - m_start_time - m_total_idle_time) * 0.001f;
	}

	f32 TimerWin32::get_delta_time() const
	{
		return m_delta_time;
	}


	void TimerWin32::reset()
	{
		m_paused_time = 0;
		m_previous_time = m_start_time = timeGetTime();
		m_stopped = false;
	}

	void TimerWin32::start()
	{
		if (m_stopped)
		{
			u32 now = timeGetTime();
			m_total_idle_time += (now - m_paused_time);
			m_previous_time = now;
			m_paused_time = 0;
			m_stopped = false;
		}
	}

	void TimerWin32::stop()
	{
		if (!m_stopped)
		{
			m_paused_time = timeGetTime();
			m_stopped = true;
		}
	}

	void TimerWin32::tick()
	{
		if (!m_stopped)
		{
			m_current_time = timeGetTime();
			m_delta_time = (u32)(m_current_time - m_previous_time) * 0.001f;
			m_previous_time = m_current_time;

			if (m_delta_time < 0.0f)
				m_delta_time = 0.0f;
		}
		else
		{
			m_delta_time = 0.0f;
		}
	}
}