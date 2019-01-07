#include <mh/app.hpp>
#include <mh/d3d11/renderer.hpp>
#include <mh/d3d11/d2d1.hpp>
#include <DxErr.h>

namespace Mh
{
	RendererD3D11::RendererD3D11()
	{}

	RendererD3D11::~RendererD3D11()
	{}

	bool RendererD3D11::initialize(const Renderer::Desc& desc)
	{
		bool success = create_device();
		if (!success) return false;
		
		::IDXGISurface* surface;
		HRESULT hr = m_swap_chain->GetBuffer(0, IID_PPV_ARGS(&surface));
		if (FAILED(hr)) return false;
		
		m_d2d = new D2D1();
		m_d2d->initialize(surface);

		surface->Release();

		return true;
	}

	void RendererD3D11::finalize()
	{
		SafeRelease(&m_swap_chain);
		SafeRelease(&m_device);
		
		if (m_d2d)
		{
			m_d2d->finalize();
			delete m_d2d;
			m_d2d = nullptr;
		}
	}

	void RendererD3D11::set_viewport(const Renderer::Viewport& viewport)
	{

	}

	bool RendererD3D11::on_resize(uint width, uint height)
	{
		return true;
	}

	bool RendererD3D11::begin_render()
	{
		return true;
	}

	void RendererD3D11::end_render()
	{

	}

	bool RendererD3D11::create_device()
	{
		::UINT createDeviceFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;	// Direct2D와 동시에 쓰기 외해 필요함
#if defined(_MH_DEBUG_)
		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;		// 왠지 안된다... 일단 제거.
#endif
		::D3D_FEATURE_LEVEL featureLevel;
		::DXGI_SWAP_CHAIN_DESC sd;
		sd.BufferDesc.Width = 720;// m_client_width;
		sd.BufferDesc.Height = 640; // m_client_height;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		// 멀티샘플링... 안씀
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;

		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.BufferCount = 1;
		sd.OutputWindow = static_cast<WinApp*>(App::get_instance_ptr())->get_window_handle();
		sd.Windowed = TRUE;
		sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		sd.Flags = 0;

		HRESULT hr = ::D3D11CreateDeviceAndSwapChain(
			NULL,	// default adapter
			D3D_DRIVER_TYPE_HARDWARE,		// 첫번째 인자가 NULL이 아니면 UNKNOWN으로
			NULL,	// 소프트웨어 디바이스 아님
			createDeviceFlags,
			NULL, 0,
			D3D11_SDK_VERSION,
			&sd,
			&m_swap_chain,
			&m_device,
			&featureLevel,
			&m_immediate_context
			);

		if (FAILED(hr))
		{
			DXTRACE_ERR(TEXT("D3D11CreateDevice Failed."), hr);
			return false;
		}

		if (featureLevel != D3D_FEATURE_LEVEL_11_0)
		{
			DXTRACE_MSG(TEXT("Direct3D Feature Level 11 unsupported."), hr);
		}

		return true;
	}
}