#include <mh/app.hpp>
#include <mh/renderer_d3d11.hpp>

namespace Mh
{
	RendererD3D11::RendererD3D11()
		: m_swap_chain(NULL),
		m_device(NULL),
		m_immediate_context(NULL),
		m_render_target(NULL),
		m_depth_stencil(NULL)
	{
	}

	RendererD3D11::~RendererD3D11()
	{
		finalize();
	}

	bool RendererD3D11::initialize(const Renderer::Desc& desc)
	{
		m_client_width = desc.width;
		m_client_height = desc.height;

		if (!this->create_device())
			return false;

		m_device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &m_4x_msaa_quality);
		assert(m_4x_msaa_quality > 0);

		this->on_resize();

		return true;
	}

	void RendererD3D11::finalize()
	{
		SafeRelease(&m_depth_stencil);
		SafeRelease(&m_render_target);
		SafeRelease(&m_swap_chain);
		SafeRelease(&m_immediate_context);
		SafeRelease(&m_device);
	}

	bool RendererD3D11::on_resize(uint width, uint height)
	{
		m_client_width = width;
		m_client_height = height;
		on_resize();
		return true;
	}

	bool RendererD3D11::begin_render()
	{
		return true;
	}

	void RendererD3D11::end_render()
	{
		m_swap_chain->Present(0, 0);
	}

	void RendererD3D11::set_viewport(const Renderer::Viewport& viewport)
	{

	}

	// D3D11 디바이스 작성
	bool RendererD3D11::create_device()
	{
		::UINT createDeviceFlags = 0;
#if defined(_MH_DEBUG_)
		//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;		// 왠지 안된다... 일단 제거.
#endif
		::D3D_FEATURE_LEVEL featureLevel;
		::DXGI_SWAP_CHAIN_DESC sd;
		sd.BufferDesc.Width = m_client_width;
		sd.BufferDesc.Height = m_client_height;
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

		if( featureLevel != D3D_FEATURE_LEVEL_11_0 )
		{
			DXTRACE_ERR(TEXT("Direct3D Feature Level 11 unsupported."), hr);
			return false;
		}

		return true;
	}

	void RendererD3D11::on_resize()
	{
		SafeRelease(&m_render_target);
		SafeRelease(&m_depth_stencil);

		// 렌더 타겟 뷰 작성
		m_swap_chain->ResizeBuffers(1, m_client_width, m_client_height, DXGI_FORMAT_R8G8B8A8_UNORM, 0);
		ID3D11Texture2D* backBuffer;
		CHECK_HR(m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer)));
		CHECK_HR(m_device->CreateRenderTargetView(backBuffer, 0, &m_render_target));
		SafeRelease(&backBuffer);

		// 깊이-스텐실 뷰 작성
		::D3D11_TEXTURE2D_DESC dsd;
		dsd.Width = m_client_width;
		dsd.Height = m_client_height;
		dsd.MipLevels = 1;
		dsd.ArraySize = 1;
		dsd.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		dsd.SampleDesc.Count = 1;
		dsd.SampleDesc.Quality = 0;
		dsd.Usage = D3D11_USAGE_DEFAULT;
		dsd.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		dsd.CPUAccessFlags = 0; 
		dsd.MiscFlags = 0;

		CHECK_HR(m_device->CreateTexture2D(&dsd, NULL, &m_depth_stencil_buffer));
		CHECK_HR(m_device->CreateDepthStencilView(m_depth_stencil_buffer, 0, &m_depth_stencil));

		m_immediate_context->OMSetRenderTargets(1, &m_render_target, m_depth_stencil);
	}
}