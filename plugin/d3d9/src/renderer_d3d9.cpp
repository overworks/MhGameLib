
#include <mh/win32/winapp.hpp>
#include <mh/renderer_d3d9.hpp>

namespace Mh
{
	RendererD3D9::RendererD3D9()
		: m_d3d(nullptr), m_device(nullptr)
	{
	}

	RendererD3D9::~RendererD3D9()
	{
		finalize();
	}

	bool RendererD3D9::initialize(const Renderer::Desc& desc)
	{
		m_d3d = ::Direct3DCreate9(D3D_SDK_VERSION);
		if (!m_d3d)
		{
			MessageBoxW(0, L"Could not create Direct3D9 Object", nullptr, 0);
			return false;
		}

		::HWND hwnd = static_cast<const WinApp*>(App::get_instance_ptr())->get_window_handle();
		::DWORD behaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		::D3DPRESENT_PARAMETERS dpp = {};
		dpp.BackBufferWidth = desc.width;
		dpp.BackBufferHeight = desc.height;
		dpp.BackBufferFormat = ::D3DFMT_X8R8G8B8;
		dpp.BackBufferCount = 1;
		dpp.MultiSampleType = ::D3DMULTISAMPLE_NONE;
		dpp.MultiSampleQuality = 0;
		dpp.SwapEffect = ::D3DSWAPEFFECT_DISCARD;
		dpp.hDeviceWindow = hwnd;
		dpp.Windowed = TRUE;
		dpp.EnableAutoDepthStencil = TRUE;
		dpp.AutoDepthStencilFormat = ::D3DFMT_D24S8;
		dpp.Flags = 0;
		dpp.FullScreen_RefreshRateInHz = 0;
		dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;

		HRESULT hr = m_d3d->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hwnd,
			behaviorFlags,
			&dpp,
			&m_device
		);

		if (FAILED(hr))
		{
			MessageBoxW(0, L"Could not create Direct3DDevice9 Object", nullptr, 0);
			SafeRelease(&m_d3d);
			return false;
		}

		return true;
	}

	void RendererD3D9::finalize()
	{
		SafeRelease(&m_d3d);
	}

	bool RendererD3D9::begin_render()
	{
		return true;
	}

	void RendererD3D9::end_render()
	{
	}
}