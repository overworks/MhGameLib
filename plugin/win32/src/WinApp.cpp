#include <tchar.h>
#include <mh/winapp.hpp>
#include <mh/renderer.hpp>
#include <mh/timer_win32.hpp>

namespace Mh
{
	WinApp::WinApp(HINSTANCE hInstance)
	{
		m_hinst = hInstance;
	}

	WinApp::~WinApp()
	{

	}

	bool WinApp::initialize(uint width, uint height, LPCWSTR title)
	{
		::WNDCLASSEXW wcex = { 0 };
		wcex.cbSize = sizeof(::WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.hInstance = m_hinst;
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.lpszClassName = L"MhWinApp";
		if (!::RegisterClassExW(&wcex))
		{
			return false;
		}

		::RECT rect = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
		::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
		m_hwnd = ::CreateWindowW(wcex.lpszClassName, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left, rect.bottom - rect.top, nullptr, nullptr, m_hinst, this);

		m_dxgi.create_factory();
		
		m_d2d1.initialize(m_hwnd);

		if (!m_hid.initialize(m_hwnd))
		{
			return false;
		}
		
		return true;
	}

	int WinApp::run(int cmd_show)
	{
		::ShowWindow(m_hwnd, cmd_show);

		::timeBeginPeriod(1);
		
		TimerWin32 timer;
		timer.reset();

		f32 accumulated_time = 0.0f;
		f32 time_per_frame = 1.0f / 60.0f;

		::MSG msg = { 0 };
		bool running = true;
		while (running)
		{
			while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);

				if (msg.message == WM_QUIT)
					running = false;
			}
		
			timer.tick();

			accumulated_time += timer.get_delta_time();

			// 게임 루프에다가 남은 시간을 전달해줘야한다.
			// 고정 프레임으로 할것인지, 가변 프레임으로 할것인지, 가변 시간인지 등등 미리 옵션에서 결정하도록 하는 처리가 필요.
			while (accumulated_time >= time_per_frame)
			{
				game_loop();
				accumulated_time -= time_per_frame;
			}
		}

		::timeEndPeriod(1);

		return static_cast<int>(msg.lParam);
	}

	LRESULT CALLBACK WinApp::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		WinApp* app = reinterpret_cast<WinApp*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		switch (msg)
		{
		case WM_CREATE:
			{
				LPCREATESTRUCT create_struct = reinterpret_cast<LPCREATESTRUCT>(lParam);
				SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(create_struct->lpCreateParams));
			}
			return 0;

		case WM_INPUT:
			if (GET_RAWINPUT_CODE_WPARAM(wParam) == RIM_INPUT)
				app->get_hid().on_message((HRAWINPUT)lParam);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}