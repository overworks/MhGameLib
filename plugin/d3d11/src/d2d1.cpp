#include <mh/prerequisite.h>
#include <mh/util.hpp>
#include <mh/d3d11/d2d1.hpp>

namespace Mh
{
	D2D1::D2D1()
		: m_factory(nullptr), m_render_target(nullptr)
	{
	}

	D2D1::~D2D1()
	{
	}

	bool D2D1::initialize(IDXGISurface* surface)
	{
		HRESULT hr;

		D2D1_FACTORY_OPTIONS options = {};
#ifdef _MH_DEBUG_
		options.debugLevel = D2D1_DEBUG_LEVEL_WARNING;
#endif
		hr = ::D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, options, &m_factory);
		if (SUCCEEDED(hr))
		{
			FLOAT dpi_x, dpi_y;
			m_factory->GetDesktopDpi(&dpi_x, &dpi_y);

			// 렌더타겟 생성
			D2D1_RENDER_TARGET_PROPERTIES property = {};
			property.type = D2D1_RENDER_TARGET_TYPE_DEFAULT;
			property.pixelFormat.format = ::DXGI_FORMAT_UNKNOWN;
			property.pixelFormat.alphaMode = ::D2D1_ALPHA_MODE_PREMULTIPLIED;
			property.dpiX = dpi_x;
			property.dpiY = dpi_y;

			hr = m_factory->CreateDxgiSurfaceRenderTarget(surface, property, &m_render_target);
		}

		return SUCCEEDED(hr);
	}

	void D2D1::finalize()
	{
		SafeRelease(&m_factory);
		SafeRelease(&m_render_target);
	}
}