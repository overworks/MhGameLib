#ifndef _MH_D2D_1_HPP_
#define _MH_D2D_1_HPP_

#include <DXGI.h>
#include <d2d1.h>

namespace Mh
{
	struct D2D1Trait
	{
		typedef ::ID2D1Factory		Factory;
		typedef	::ID2D1RenderTarget	RenderTarget;
	};

	class D2D1 : public D2D1Trait
	{
	public:
		D2D1();
		virtual ~D2D1();

		virtual bool initialize(IDXGISurface* surface);
		virtual void finalize();

	private:
		Factory*		m_factory;
		RenderTarget*	m_render_target;
	};
}

#endif /* _MH_D2D_1_HPP_ */