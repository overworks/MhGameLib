#ifndef _MH_D3D11_RENDERER_HPP_
#define	_MH_D3D11_RENDERER_HPP_

#include <d3d11.h>
#include <mh/renderer.hpp>
#include "dxgi11.hpp"

namespace Mh
{
	class D2D1;

	class RendererD3D11 : public Renderer, public DXGI11Trait
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

	private:
		bool create_device();

	private:
		SwapChain*		m_swap_chain;
		Device*			m_device;
		DeviceContext*	m_immediate_context;
		D2D1*			m_d2d;
	};
}

#endif	/* _MH_D3D11_RENDERER_HPP_ */