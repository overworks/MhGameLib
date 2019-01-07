#ifndef _MH_WINAPP_HPP_
#define _MH_WINAPP_HPP_

#include <Windows.h>
#include <mh/app.hpp>
#include <mh/dxgi.hpp>
#include <mh/d2d1.hpp>
#include <mh/hid.hpp>

namespace Mh
{
	class MH_CLASS WinApp : public App
	{
	public:
		WinApp(HINSTANCE instance);
		virtual ~WinApp();

		virtual bool initialize(uint width, uint height, LPCWSTR title);
		virtual int run(int cmd_show);

		HID& get_hid() { return m_hid; }
		const HID& get_hid() const { return m_hid; }

	private:
		HINSTANCE m_hinst;
		HWND m_hwnd;
		DXGIWrapper1 m_dxgi;
		D2D1Wrapper m_d2d1;
		HID m_hid;

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	};
}

#endif /* _MH_WINAPP_HPP_ */
