#include <Windows.h>
#include <DxErr.h>
#include <mh/d3d11/dxgi11.hpp>

namespace Mh
{
	DXGI11Trait::Factory* DXGI11Trait::create_factory()
	{
		Factory* factory = NULL;
		HRESULT hr = ::CreateDXGIFactory1(__uuidof(Factory), (void**)&factory);
		if (FAILED(hr))
			DXTRACE_ERR(TEXT("Could not create a factory"), hr);

		return factory;
	}

	DXGI11Trait::Adapter* DXGI11Trait::get_adapter(Factory* factory)
	{
		Adapter* adapter = NULL;
		HRESULT hr = factory->EnumAdapters1(0, &adapter);
		if (FAILED(hr))
			DXTRACE_ERR(TEXT("Could not enumerate adapters"), hr);
			
		return adapter;
	}
}