#ifndef _MH_DXGI_1_1_HPP_
#define _MH_DXGI_1_1_HPP_

#include <dxgi.h>

namespace Mh
{
	struct DXGI11Trait
	{
		typedef ::IDXGIAdapter1		Adapter;
		typedef	::IDXGIDevice1		Device;
		typedef	::IDXGIFactory1		Factory;
		typedef	::IDXGIOutput		Output;
		typedef	::IDXGISurface1		Surface;
		typedef ::IDXGISwapChain	SwapChain;

		static Factory* create_factory();
		static Adapter* get_adapter(Factory* factory);
	};
}

#endif /* _MH_DXGI_1_1_HPP_ */