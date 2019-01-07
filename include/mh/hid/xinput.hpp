#ifndef	_MH_HID_XINPUT_HPP_
#define	_MH_HID_XINPUT_HPP_

#include "gamepad.hpp"
#include "manager.hpp"
#include <windows.h>
#include <xinput.h>

namespace Mh
{
	namespace HID
	{
		/*!
		 *	Xinput 게임패드 클래스
		 */
		class GamepadXI : public Gamepad
		{
		public:
			GamepadXI( uint index );
			virtual ~GamepadXI();
			HID_GAMEPAD_DERIVED_INTERFACE();

			bool is_connected() const	{ return m_connected; }

		private:
			bool			m_connected;
			::XINPUT_STATE	m_state;
		};

		/*!
		 *	XInput 장치 관리자
		 */
		class ManagerXI : public Manager
		{
		public:
			ManagerXI();
			virtual ~ManagerXI();
			HID_MANAGER_DERIVED_INTERFACE();

		private:
			GamepadXI*	m_gamepad[4];
		};

	}	// namespace Mh::HID
}		// namespace Mh

#endif	/* _MH_HID_XINPUT_HPP_ */