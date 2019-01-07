#ifndef	_MH_RENDERER_D3D11_HPP_
#define	_MH_RENDERER_D3D11_HPP_

#include "base.hpp"
#include "dxgi.hpp"
#include "d2d1.hpp"
#include <d3d11.h>

namespace Mh
{
	class RendererD3D11 : public Renderer
	{
	public:
		typedef	::ID3D11Device				Device;
		typedef	::ID3D11DeviceContext		DeviceContext;
		typedef	::ID3D11RenderTargetView	RenderTarget;
		typedef	::ID3D11DepthStencilView	DepthStencilView;
		typedef	::ID3D11Texture1D			Texture1D;
		typedef	::ID3D11Texture2D			Texture2D;
		typedef	::ID3D11Texture3D			Texture3D;

	public:
		RendererD3D11();
		virtual ~RendererD3D11();
		RENDERER_DERIVED_INTERFACE();

		void	set_clear_color( const float* color );

	private:
		bool load_module();
		bool create_device();
		bool create_view();

	private:
		::HMODULE			m_module;
		Device*				m_device;
		DeviceContext*		m_immediate_context;
		RenderTarget*		m_render_target;
		DepthStencilView*	m_depth_stencil;

		DXGI11		m_dxgi;
		D2D1		m_d2d1;
	};

}		// namespace Mh

#endif	/* _MH_RENDERER_D3D11_HPP_ */