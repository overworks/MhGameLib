#ifndef	_MH_RENDERER_D3D11_HPP_
#define	_MH_RENDERER_D3D11_HPP_

#include <d3d11.h>
#include <mh/renderer.hpp>
#include "dxgi11.hpp"

#ifndef	CHECK_HR
#ifdef	_MH_DEBUG_
#define	CHECK_HR(x)\
	{\
		HRESULT _hr = (x);\
		if (FAILED(_hr))\
		{\
			WCHAR path[256];\
			MultiByteToWideChar(CP_ACP, 0, __FILE__, -1, path, 256);\
			DXTraceW(path, (DWORD)__LINE__, _hr, L#x, TRUE); \
		}\
	}
#else
#define	CHECK_HR(x)	(x)
#endif	// _MH_DEBUG_
#endif	// CHECK_HR

namespace Mh
{
	class MH_CLASS RendererD3D11 : public Renderer
	{
	public:
		typedef	::ID3D11Device				Device;
		typedef	::ID3D11DeviceContext		DeviceContext;
		typedef	::ID3D11RenderTargetView	RenderTarget;
		typedef	::ID3D11DepthStencilView	DepthStencilView;
		typedef	::ID3D11Texture1D			Texture1D;
		typedef	::ID3D11Texture2D			Texture2D;
		typedef	::ID3D11Texture3D			Texture3D;

		typedef	DXGI11Trait::SwapChain		SwapChain;

	public:
		RendererD3D11();
		virtual ~RendererD3D11();
		RENDERER_DERIVED_INTERFACE();

		void	set_clear_color( const float* color );

	private:
		bool create_device();
		bool create_view();
		void on_resize();

	private:
		SwapChain*			m_swap_chain;
		Device*				m_device;
		DeviceContext*		m_immediate_context;
		RenderTarget*		m_render_target;
		DepthStencilView*	m_depth_stencil;
		Texture2D*			m_depth_stencil_buffer;
		
		uint	m_client_width;
		uint	m_client_height;

		uint	m_4x_msaa_quality;
	};

}		// namespace Mh

#endif	/* _MH_RENDERER_D3D11_HPP_ */