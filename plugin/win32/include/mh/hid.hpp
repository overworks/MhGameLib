#ifndef _MH_HID_HPP_
#define	_MH_HID_HPP_

#include <mh/types.hpp>
#include <Windows.h>

namespace Mh
{
	enum MouseEvent
	{
		MOUSE_EVENT_MOVE,
		MOUSE_EVENT_BUTTON_DOWN,
		MOUSE_EVENT_BUTTON_UP,
	};

	enum MouseButtonState
	{
		MOUSE_BUTTON_STATE_RELEASED,
		MOUSE_BUTTON_STATE_DOWN,
		MOUSE_BUTTON_STATE_UP,
	};

	enum MouseButton
	{
		MOUSE_BUTTON_LEFT,
		MOUSE_BUTTON_RIGHT,
		MOUSE_BUTTON_MIDDLE,
		MOUSE_BUTTON_X1,
		MOUSE_BUTTON_X2,

		MOUSE_BUTTON_MAX,
	};

	struct MouseStatus
	{
		s32 x, y;
		s32 wheel_delta;
		MouseButtonState button_state[MOUSE_BUTTON_MAX];
	};

	enum KeyboardEvent
	{
		KEY_DOWN,
		KEY_UP,
	};

	class HID
	{
	public:
		typedef void(*MouseReceiver)(int x, int y);

	public:
		HID();
		~HID();
		bool initialize(HWND hwnd);

		void on_message(HRAWINPUT handle);

	private:
		s32 m_mouse_x;
		s32 m_mouse_y;
		s32 m_mouse_wheel_delta;
		MouseButtonState m_mouse_button_status[5];
		
		bool m_key_state[256];
		
		// 키보드는 40바이트, 마우스는 48바이트를 사용함. raw_input으로 두개만 사용할 예정이므로 미리 확보.
		BYTE m_raw_data_buffer[48];

	};
}

#endif // !_MH_HID_HPP_
