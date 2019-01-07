#ifndef	_MH_RENDERER_D3D10_HPP_
#define	_MH_RENDERER_D3D10_HPP_

#include "base.hpp"
#include "dxgi.hpp"
#include <d3d10.h>

namespace Mh
{
	class RendererD3D10 : public Renderer
	{
	public:
		typedef	::ID3D10Device				Device;
		typedef	::ID3D10DeviceContext		DeviceContext;
		typedef	::ID3D10RenderTargetView	RenderTarget;
		typedef	::ID3D10DepthStencilView	DepthStencilView;
		typedef	::ID3D10Texture1D			Texture1D;
		typedef	::ID3D10Texture2D			Texture2D;
		typedef	::ID3D10Texture3D			Texture3D;

	public:
		RendererD3D10();
		virtual ~RendererD3D10();
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

#endif	/* _MH_RENDERER_D3D10_HPP_ */