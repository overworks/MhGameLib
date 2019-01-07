#ifndef _MH_RENDERER_D3D9_HPP_
#define _MH_RENDERER_D3D9_HPP_

#include <d3d9.h>
#include <mh/renderer.hpp>

#ifndef	CHECK_HR
#ifdef	_MH_DEBUG_
#define	CHECK_HR(x)\
	{\
		HRESULT _hr = (x);\
		if (FAILED(_hr))\
			DXTraceW(__FILE__, (DWORD)__LINE__, _hr, L#x, TRUE); \
	}
#else
#define	CHECK_HR(x)	(x)
#endif	// _MH_DEBUG_
#endif	// CHECK_HR

namespace Mh
{
	class MH_CLASS RendererD3D9 : public Renderer
	{
	public:
		typedef	::IDirect3D9		D3D;
		typedef	::IDirect3DDevice9	Device;

	public:
		RendererD3D9();
		virtual ~RendererD3D9();
		RENDERER_DERIVED_INTERFACE();

	private:
		D3D*		m_d3d;
		Device*		m_device;
	};
}

#endif // _MH_RENDERER_D3D9_HPP_