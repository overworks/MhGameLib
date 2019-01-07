#include <mh/d3d11.hpp>
#include <d3d11_app.hpp>

namespace Mh
{
	D3D11App::D3D11App(HINSTANCE hInstance, LPTSTR lpCmdLine, int nCmdShow)
		: WinApp(hInstance, lpCmdLine, nCmdShow)
	{
	}

	D3D11App::~D3D11App()
	{
	}

	bool D3D11App::initialize(LPCTSTR title, uint width, uint height)
	{
		if (!WinApp::initialize(title, width, height))
			return false;

		Renderer* renderer = new RendererD3D11();
		if (renderer)
		{
			Renderer::Desc desc;
			desc.width = width;
			desc.height = height;

			renderer->initialize(desc);
			set_renderer(renderer);
		}

		return true;
	}

	void D3D11App::finalize()
	{
		WinApp::finalize();

		Renderer* renderer = get_renderer();
		if (renderer)
		{
			renderer->finalize();
			delete renderer;
			renderer = nullptr;
			set_renderer(nullptr);
		}

	}

	int D3D11App::run()
	{
#if 1
		::MSG msg = { 0 };

		get_timer()->reset();

		while( WM_QUIT != msg.message )
		{
			if( ::PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
			{
				TranslateMessage( &msg );
				DispatchMessage( &msg );
			}
			else
			{
				get_timer()->tick();
				if (!is_paused())
				{
				}
				else
				{
					::Sleep(1);
				}
			}
		}

		return (int)msg.wParam;
#else
		return WinApp::run();
#endif
	}
}