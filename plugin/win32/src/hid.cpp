#include <cstring>
#include <tchar.h>
#include "mh/hid.hpp"

namespace Mh
{
	HID::HID()
	{
		m_mouse_x = 0;
		m_mouse_y = 0;
		m_mouse_wheel_delta = 0;

		memset(m_key_state, 0, 256);
	}

	HID::~HID()
	{

	}

	bool HID::initialize(HWND hwnd)
	{
		// Top-Level Collection의 값은 다음 웹페이지를 참조할 것
		// https://docs.microsoft.com/en-us/windows-hardware/drivers/hid/top-level-collections-opened-by-windows-for-system-use

		RAWINPUTDEVICE rid[2];

		// 키보드
		rid[0].usUsagePage = 0x01;
		rid[0].usUsage = 0x06;
		rid[0].dwFlags = RIDEV_NOLEGACY;
		rid[0].hwndTarget = hwnd;

		// 마우스
		rid[1].usUsagePage = 0x01;
		rid[1].usUsage = 0x02;
		rid[1].dwFlags = RIDEV_NOLEGACY;
		rid[1].hwndTarget = hwnd;

		if (RegisterRawInputDevices(rid, 2, sizeof(RAWINPUTDEVICE)) == FALSE)
		{
			return false;
		}

		return true;
	}

	void HID::on_message(HRAWINPUT handle)
	{
		UINT size = 48;
		if (GetRawInputData(handle, RID_INPUT, m_raw_data_buffer, &size, sizeof(RAWINPUTHEADER)))
		{
			RAWINPUT* raw = (RAWINPUT*)m_raw_data_buffer;

			if (raw->header.dwType == RIM_TYPEMOUSE)
			{
				const RAWMOUSE& raw_mouse = raw->data.mouse;

				if (raw_mouse.usFlags & MOUSE_MOVE_ABSOLUTE)
				{
					m_mouse_x = raw->data.mouse.lLastX;
					m_mouse_y = raw->data.mouse.lLastY;
				}
				else
				{
					m_mouse_x += raw->data.mouse.lLastX;
					m_mouse_y += raw->data.mouse.lLastY;
				}

				USHORT button_flags = raw_mouse.usButtonFlags;
				if (button_flags & RI_MOUSE_LEFT_BUTTON_DOWN)
				{
					m_mouse_button_status[MOUSE_BUTTON_LEFT] = MOUSE_BUTTON_STATE_DOWN;
				}
				if (button_flags & RI_MOUSE_LEFT_BUTTON_UP)
				{
					m_mouse_button_status[MOUSE_BUTTON_LEFT] = MOUSE_BUTTON_STATE_UP;
				}
				if (button_flags & RI_MOUSE_RIGHT_BUTTON_DOWN)
				{
					m_mouse_button_status[MOUSE_BUTTON_RIGHT] = MOUSE_BUTTON_STATE_DOWN;
				}
				if (button_flags & RI_MOUSE_RIGHT_BUTTON_UP)
				{
					m_mouse_button_status[MOUSE_BUTTON_RIGHT] = MOUSE_BUTTON_STATE_UP;
				}
				if (button_flags & RI_MOUSE_MIDDLE_BUTTON_DOWN)
				{
					m_mouse_button_status[MOUSE_BUTTON_MIDDLE] = MOUSE_BUTTON_STATE_DOWN;
				}
				if (button_flags & RI_MOUSE_MIDDLE_BUTTON_UP)
				{
					m_mouse_button_status[MOUSE_BUTTON_MIDDLE] = MOUSE_BUTTON_STATE_UP;
				}
				if (button_flags & RI_MOUSE_BUTTON_4_DOWN)
				{
					m_mouse_button_status[MOUSE_BUTTON_X1] = MOUSE_BUTTON_STATE_DOWN;
				}
				if (button_flags & RI_MOUSE_BUTTON_4_UP)
				{
					m_mouse_button_status[MOUSE_BUTTON_X1] = MOUSE_BUTTON_STATE_UP;
				}
				if (button_flags & RI_MOUSE_BUTTON_5_DOWN)
				{
					m_mouse_button_status[MOUSE_BUTTON_X2] = MOUSE_BUTTON_STATE_DOWN;
				}
				if (button_flags & RI_MOUSE_BUTTON_5_UP)
				{
					m_mouse_button_status[MOUSE_BUTTON_X2] = MOUSE_BUTTON_STATE_UP;
				}
				if (button_flags & RI_MOUSE_WHEEL)
				{
					
				}
			}
			else if (raw->header.dwType == RIM_TYPEKEYBOARD)
			{
				const RAWKEYBOARD& raw_keyboard = raw->data.keyboard;

				USHORT flags = raw_keyboard.Flags;
				bool keybreak = ((flags & RI_KEY_BREAK) != 0);
				bool e0 = ((flags & RI_KEY_E0) != 0);
				bool e1 = ((flags & RI_KEY_E1) != 0);

				USHORT vkey = raw_keyboard.VKey;
				if (vkey == VK_SHIFT)
				{
					if (e0) m_key_state[VK_RSHIFT] = !keybreak;
					else m_key_state[VK_LSHIFT] = !keybreak;
					m_key_state[VK_SHIFT] = m_key_state[VK_LSHIFT] || m_key_state[VK_RSHIFT];
				}
				else if (vkey == VK_CONTROL)
				{
					if (e0) m_key_state[VK_RCONTROL] = !keybreak;
					else m_key_state[VK_LCONTROL] = !keybreak;
					m_key_state[VK_CONTROL]= m_key_state[VK_LCONTROL] || m_key_state[VK_RCONTROL];
				}
				else if (vkey == VK_MENU)
				{
					if (e0) m_key_state[VK_RMENU] = !keybreak;
					else m_key_state[VK_LMENU] = !keybreak;
					m_key_state[VK_MENU] = m_key_state[VK_LMENU] || m_key_state[VK_RMENU];
				}
				else
				{
					m_key_state[vkey] = !keybreak;
				}
			}
		}
	}
}